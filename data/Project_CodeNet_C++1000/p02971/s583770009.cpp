#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for (int i = 0; i < n; i++)
#define vi vector<int>

int main(){
  int n; cin >> n;
  vi a(n); rep(i, n) cin >> a[i];

  //a[0], a[1], a[2]
  vi lm(n);// lm[i]; iより左にある者たちの中でのmax。 便宜上 lm[0]=0 としておく
  vi rm(n);// rm[i]; iより右にある者たちの中でのmax。 便宜上 rm[n-1] = 0
  // 求める値は max(lm[i],rm[i]) (i = 0,1,2,...,n-1) の最大値

  for(int i = 1; i < n; i++) lm[i] = max(lm[i-1],a[i-1]);
  for(int i = n-2; i >= 0; i--) rm[i] = max(rm[i+1],a[i+1]);

  rep(i, n) cout << max(lm[i], rm[i]) << '\n';
}