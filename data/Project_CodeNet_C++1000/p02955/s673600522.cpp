#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<cstdio>
#include<cmath>
#include<deque>
#include<numeric>
#include<queue>
#include<stack>
#include<cstring>
#include<limits>
#include<functional>
#include<unordered_set>
#include<iomanip>
#include<cassert>
#include<regex>
#include<bitset>
#include<complex>
#include<chrono>
#define rep(i,a) for(int i=(int)0;i<(int)a;++i)
#define pb push_back
#define eb emplace_back
using ll=long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 60;
 
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
 
using namespace std;
//ここから
ll n,k;
vector<ll>a;
#define int64_t ll
vector< int64_t > divisor(int64_t n) {
  vector< int64_t > ret;
  for(int64_t i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}
bool C(ll mid,ll x){
  if(x%mid)return false;
  vector<ll>p(n);
  rep(i,n){
    p[i]=a[i]%mid;
  }
  sort(p.begin(),p.end());
  ll sum=0,sum2=0;
  int pos=0;
  while(pos<n&&p[pos]+sum<=k){
    sum+=p[pos++];
  }
  for(int i=pos;i<n;++i){
    sum2+=p[i];
  }
  return sum2<=k;
}

void solve(){
  cin>>n>>k;
  a.resize(n);
  ll sum=0;
  rep(i,n){
    cin>>a[i];
    sum+=a[i];
  }
  ll ans=0;
  vector<ll>v=divisor(sum);
  vector<ll>p(n);
  rep(j,v.size()){
    rep(i,n){
      p[i]=a[i]%v[j];
    }
    sort(p.begin(),p.end());
    ll sum=0,sum2=0;
    int pos=0;
    while(pos<n&&p[pos]+sum<=k){
      sum+=p[pos++];
    }
    for(int i=pos;i<n;++i){
      sum2+=v[j]-p[i];
    }
    if(sum2<=k){
      chmax(ans,v[j]);
    }
  }
  cout<<ans<<endl;
}

int main(){
	ios::sync_with_stdio(false);
  cin.tie(0);
	cout<<fixed<<setprecision(15);
	solve();
	return 0;
}
