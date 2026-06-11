#include<bits/stdc++.h>

using namespace std;

// http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_D&lang=jp

int LIS(int n,vector<int> a) {
  vector<int> dp(n+1,INT_MAX);
  for(int i=0;i<n;++i) {
    *lower_bound(dp.begin(),dp.end(),a[i]) = a[i];
  }
  return lower_bound(dp.begin(),dp.end(),INT_MAX) - dp.begin();
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;++i) cin >> a[i];
  cout << LIS(n,a) << endl;
  return 0;
}