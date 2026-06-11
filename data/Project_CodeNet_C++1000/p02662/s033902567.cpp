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
  ll n,s,mod=998244353;cin>>n>>s;
  lvector A(n),f(3010,0),ff(f);rep(i,n) cin>>A[i];
  f[0]=1;
  for(ll a:A) {
    rep(i,3010) ff[i]=2*f[i];
    for(ll i=a;i<3010;++i) ff[i]+=f[i-a];
    rep(i,3010) ff[i]%=mod;
    f=ff;
  }
  print(f[s]);
  return 0;
}