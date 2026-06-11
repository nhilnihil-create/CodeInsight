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

bool cmp(const pair<long long, long long> &q, const pair<long long, long long> &w) {
    if (q == w)
        return false;
    if (q == make_pair(0ll, 0ll))
        return true;
    if (w == make_pair(0ll, 0ll))
        return false;
    bool side1 = (q.second > 0 || q.second == 0 && q.first < 0);
    bool side2 = (w.second > 0 || w.second == 0 && w.first < 0);
 
    if (side1 != side2) {
        return side1 < side2;
    }
 
    long vp = q.first * w.second - q.second * w.first;
    return vp > 0;
}

int main() {
  long long n;
  cin >> n;
  vector<pair<long double, long double> > a(2 * n);
  for(int i = 0; i < n; ++i){
    cin >> a[i].first >> a[i].second;
    a[i + n].first = -a[i].first;
    a[i + n].second = -a[i].second;
  } 

  long double x1 = 0, y1 = 0;
  for(int i = 0; i < n; ++i){
    if(a[i].second > 0 || (!a[i].second && a[i].first < 0)){
      x1 += a[i].first;
      y1 += a[i].second;
    }
  }
  sort(a.begin(), a.end(), cmp);
  long double mx = 0;
  for(int i = 0; i < 2 * n; ++i){
    x1 += a[i].first;
    y1 += a[i].second;
    mx = max(mx, sqrt(x1 * x1 + y1 * y1));
  } 
  cout << fixed << setprecision(20) << mx;
}