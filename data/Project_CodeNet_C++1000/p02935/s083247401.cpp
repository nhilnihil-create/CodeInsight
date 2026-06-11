#include <bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<cstring>
#include<math.h>
#include<map>
#include<bitset>
#include<iomanip>
#include<queue>
#include<functional>
#include<stack>
#include<tuple>
#include<cassert>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using P = pair<int, int>;

int main() {
  double N;
  vector<double> v;
  cin >> N;
  for(double i = 0; i < N; i++) {
    double temp;
    cin >> temp;
    v.push_back(temp);
  }
  sort(v.begin(), v.end());
  double ans = v[0];
  for(double i = 1; i < N; i++) {
    ans = (ans + v[i]) / 2;
  }
  cout << std::fixed << std::setprecision(6) << ans << endl;
  return 0;
}