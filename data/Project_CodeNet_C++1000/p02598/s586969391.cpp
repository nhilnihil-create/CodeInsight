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
  ll N,K;
  cin>>N>>K;
  ll a[N];
  rep(i,N) cin>>a[i];
  
  ll lb=0,ub=INF;
  
  while(ub-lb>1){
    ll mid=(lb+ub)/2;
    ll num=0;
    for(int i=0;i<N;i++){
      num+=(a[i]-1)/mid;
    }
    if(num>K) lb=mid;
    else ub=mid;
  }
  int ans=ub;
  if(ub>ans) ans++;
  cout<<ans<<endl;
  
}
