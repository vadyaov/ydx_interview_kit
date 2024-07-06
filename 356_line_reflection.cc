
/*
 * Description
 * Given n points on a 2D plane, find if there is such a line parallel to the y-axis that reflects the given points symmetrically.
 * 
 * In other words, answer whether or not if there exists a line that after reflecting all points over the given line,
 * the original points' set is the same as the reflected ones.
 * 
 * Note that there can be repeated points.
 *
 * Example 1:
 * 
 * Input: points = [[1,1],[-1,1]]
 * Output: true
 * Explanation: We can choose the line x = 0.
 * 
 * Example 2:
 * 
 * Input: points = [[1,1],[-1,-1]]
 * Output: false
 * Explanation: We can't choose a line.
 * 
 * Constraints:
 * n == points.length
 * 1 <= n <= 104
 * -10^8 <= points[i][j] <= 10^8
 * 
 * */

#include <bits/stdc++.h>

using namespace std;

bool isReflected(vector<vector<int>>& points)
{
  set<pair<int, int>> pnts;
  int x_min = INT_MAX;
  int x_max = INT_MIN;

  for (auto& point : points)
  {
    x_min = min(x_min, point[0]);
    x_max = max(x_max, point[0]);

    pnts.insert(make_pair(point[0], point[1]));
  }

  int distance = x_min + x_max;

  for (auto& p : pnts)
  {
    if (!pnts.count({distance - p.first, p.second}))
    {
      return false;
    }
  }

  return true;
}