#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;

int main(){ 
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  vector<ll> cum(n+1,0);
  rep(i,n) cum[i + 1] = cum[i] + a[i];
  ll res = 0;
  map<ll,int> mp;
  for (int r = 0; r <= n; r++) {
    int l = max(0,r - k);
    if (r - l >= k) mp[(cum[l] - l + k) % k]--; 
    res += mp[(cum[r] - r + k) % k];
    mp[(cum[r] - r + k) % k]++;
  }
  cout << res << endl;
  return 0; 
} 