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
#include<random>
#define rep(i,a) for(int i=(int)0;i<(int)a;++i)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(),x.end()
using ll=long long;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = 1LL << 60;

ll gcd(ll n, ll m) {
	ll tmp;
	while (m!=0) {
		tmp = n % m;
		n = m;
		m = tmp;
	}
	return n;
}

ll lcm(ll n, ll m) {
	return abs(n * m) / gcd(n, m);//gl=xy
}
 
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

void solve(){
  ll n;
  cin>>n;
  vector<ll>p(n);
  rep(i,n)cin>>p[i];
  vector<ll>idx(n);
  rep(i,n){
    p[i]--;
    idx[p[i]]=i+1;
  }
  multiset<ll>ms;
  ms.emplace(0);ms.emplace(0);
  ms.emplace(n+1);ms.emplace(n+1);
  ll ans=0;
  for(ll id=n-1;id>=0;--id){
    ms.emplace(idx[id]);
    auto itr=ms.lower_bound(idx[id]);
    ll sum=(*next(next(itr))-*next(itr))*(*itr-*prev(itr))+(*prev(itr)-*prev(prev(itr)))*(*next(itr)-*itr);
    //cerr<<sum<<endl;
    ans+=sum*(id+1);
  }
  cout<<ans;
}

int main(){
	ios::sync_with_stdio(false);
  cin.tie(0);
	cout<<fixed<<setprecision(15);
  solve();
	return 0;
}
