#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <iterator>
#include <iomanip>
using namespace std;


int main() {
  long long n;
  cin >> n;
  vector<pair<long long, long long> > a(n);
  for(int i = 0; i < n; ++i){
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a.rbegin(), a.rend());
  vector<vector<long long> > d(n + 1, vector<long long>(n + 1));
  for(int i = 0; i < n; ++i)
      for(int j = 0; i + j < n; ++j){
        long long k = i + j;
        d[i + 1][j] = max(d[i + 1][j], d[i][j] + a[k].first * abs(a[k].second - i));
        d[i][j + 1] = max(d[i][j + 1], d[i][j] + a[k].first * abs(-n + j + 1 + a[k].second));
      }
  long long ans = 0;
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < n; ++j) ans = max(ans, d[i][j]);
  }
  cout << ans;
}