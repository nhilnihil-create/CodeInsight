#include <iostream>
#include <stdio.h>
#include <stack>

using namespace std;




int main() {
  stack<int> slope_down;
  stack<pair<int, int> > slope_up;
  int now = 0, left = 0;
  int pool_area = 0, puddle_area = 0;
  int pools[10000];
  int pool_num;
  
  char ground;

  while (cin >> ground) {
    switch (ground) {
      case '\\':
        slope_down.push(now);
        break;
      case '/':
        if (slope_down.size() > 0) {
          left = slope_down.top();
          slope_down.pop();
          puddle_area = now - left;
          pool_area += puddle_area;

          while (slope_up.size() > 0 && slope_up.top().first > left) {
            puddle_area += slope_up.top().second;
            slope_up.pop();
          }
          slope_up.push(make_pair(left, puddle_area));
        }

        break;
      case '_':
        break;
      default:
        break;
    }
    now ++;
  }
  cout << pool_area << endl;

  pool_num = slope_up.size();
  for (int i = 0; i < pool_num; i ++) {
    pools[i] =  slope_up.top().second;
    slope_up.pop();
  }
  cout << pool_num;
  if (pool_num == 0) cout << endl;
  else cout << " ";

  for (int i = pool_num - 1; i >= 0; i --) {
    cout << pools[i];
    if (i == 0) cout << endl;
    else cout << " ";
  }

  return 0;
}

