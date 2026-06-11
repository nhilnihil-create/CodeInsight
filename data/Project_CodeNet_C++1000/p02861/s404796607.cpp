#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#define rep(i,s,e) for (int64_t i=s; i<e; i++)
#define pi 3.14159265358979323846264338327950L
using namespace std;

int main() {
  int N;
  cin >> N;
  cout << fixed << setprecision(18);
  vector<long double> x(N);
  vector<long double> y(N);
  rep(i,0,N) {
    cin >> x[i] >> y[i];
  }
  long double S=0, ans;
  rep(i,0,N) {
    rep(j,0,N) {
      S+=sqrt(pow((x[i]-x[j]),2)+pow((y[i]-y[j]),2));
    }
  }
  ans=S/N;
  cout << ans << endl;
}