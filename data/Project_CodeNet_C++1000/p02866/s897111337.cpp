#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(vec) vec.begin(),vec.end()
typedef long long ll;
typedef pair<ll,ll> pll;
typedef pair<int,int> pii;
const ll mod=998244353;
const int inf=1<<30;

ll rui(ll a,ll n){
  ll ans=1;
  while(n>0){
    if(n&1) ans=ans*a%mod;
    a=a*a%mod;
    n/=2;
  }
  return ans;
}

int main(){
  int n; cin >> n;
  vector<ll> d(n);
  rep(i,n) cin >> d[i];
  if(d[0]!=0){
    cout << 0 << endl;
    return 0;
  }
  map<ll,ll> mp;
  rep(i,n){
    mp[d[i]]++;
  }
  ll ans=1;
  for(auto c:mp){
    if(c.first==0&&c.second!=1){
      cout << 0 << endl;
      return 0;
    }
    if(c.first>0){
      ans*=rui(mp[c.first-1],c.second);
      ans%=mod;
    }
  }
  cout << ans << endl;
}