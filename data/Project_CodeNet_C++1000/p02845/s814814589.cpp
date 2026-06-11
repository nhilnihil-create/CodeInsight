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
  ll n,ans=1,mod=1e9+7,v;cin>>n;
  lvector A(n),T(3,0);rep(i,n) cin>>A[i];
  if(A[0]!=0) {print(0);return 0;}
  ans*=3;T[0]=1;
  for(ll i=1;i<n;++i) {
    v=0;
    rep(j,3) if(T[j]==A[i]) v++;
    ans=(ans*v)%mod;
    rep(j,3) if(T[j]==A[i]) {T[j]++;break;}
  }
  print(ans);
  return 0;
}