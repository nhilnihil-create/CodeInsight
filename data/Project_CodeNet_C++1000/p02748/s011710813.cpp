#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define pi 3.14159265359
#define all(i) i.begin(),i.end()
using namespace std;
const long long INF=1e9+7;
const string alp="abcdefghijklmnopqrstuvwxyz"; //26
const string ALP="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
//const ll MOD=998244353LL;
//const ll MOD=1777777777LL;


int main() {
  ll A,B,M;
  cin>>A>>B>>M;
  vl a(A);
  vl b(B);
  rep(i,A) cin>>a[i];
  rep(i,B) cin>>b[i];
  ll ans=INF;
  ll x[M],y[M],c[M];
  rep(i,M){
    cin>>x[i]>>y[i]>>c[i];
    ans=min(ans,a[x[i]-1]+b[y[i]-1]-c[i]);
  }
  sort(all(a));
  sort(all(b));
  ans=min(ans,a[0]+b[0]);
  cout<<ans<<endl;
  
}