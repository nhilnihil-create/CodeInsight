#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll>
#define cvector vector<char>
#define svector vector<string>
#define lque queue<ll>
#define lpque priority_queue<ll>
#define dlpque priority_queue<ll,lvector,greater<ll>>
#define P pair<ll,ll>
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define rep(i,n) for(ll i=0; i<n; ++i)
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,m;cin>>n>>m;
  lvector a(m+10,0),b(m+10,0);
  vector<lvector> c(20,lvector(m+10,0));
  rep(i,m) {
    cin>>a[i+1]>>b[i+1];
    rep(j,b[i+1]) {cin>>c[j+1][i+1];}
  }
  ll inf=1e9,tmp;
  lvector dp(5000,inf);dp[0]=0;
  for(ll k=1;k<=m;k++) {
    tmp=0;
    for(ll j=1;j<=b[k];++j) tmp|=(1<<(c[j][k]-1));
    for(ll bits=0;bits<(1<<n);bits++) dp[bits|tmp]=min(dp[bits|tmp],dp[bits]+a[k]);
  }
  print((dp[(1<<n)-1]==inf)?-1:dp[(1<<n)-1]);
  return 0;
}