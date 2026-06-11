#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (int)(n);i++)
using ll = long long;
const ll MOD=1000000007;
//const ll MOD=998244353;
const long long INF = 1LL << 60;
const double pi=acos(-1.0);

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }



int main()
{
  ll N,M; cin>>N>>M;
  vector<ll> A(N); rep(i,N) cin>>A[i];
  
  map<ll,ll> mp; rep(i,N) mp[A[i]]++;
  rep(i,M){
    ll a,num; tie(a,num)=*rbegin(mp);
    num--; if(num==0) mp.erase(a); else mp[a]--;
    mp[a/2]++;
  }
  
  ll ans=0;
  for(auto p:mp){
    ll a,num; tie(a,num)=p;
    ans+=a*num;
  }
  
  cout<<ans<<endl;
    
  return 0;
}