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

using P=pair<int,int>;
void solve(){
  int n;
  cin>>n;
  vector<int>s(1<<n);
  map<int,int>mp;
  rep(i,(1<<n))cin>>s[i],mp[-s[i]]++;
  vector<int>v;
  v.pb(mp.begin()->first);
  mp[mp.begin()->first]--;
  if(mp.begin()->second==0)mp.erase(mp.begin());
  bool ng=false;
  rep(i,n){
    int sz=v.size();
    rep(j,sz){
      auto itr=mp.upper_bound(v[j]);
      if(itr==mp.end())ng=true;
      else{
        v.pb(itr->first);
        mp[itr->first]--;
        if(mp[itr->first]==0)mp.erase(itr);
      }
    }
    sort(all(v));
  }
  if(ng)cout<<"No";
  else cout<<"Yes";
}

int main(){
	ios::sync_with_stdio(false);
  cin.tie(0);
	cout<<fixed<<setprecision(15);
  solve();
	return 0;
}
