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

void solve(){
  ll n,k;
  cin>>n>>k;
  vector<ll>a(n);
  rep(i,n)cin>>a[i];
  vector<ll>sum(n+1);
  map<ll,ll>mp;
  rep(i,n){
    sum[i+1]=sum[i]+a[i]-1;
  }
  ll cnt=0;
  rep(i,n){
    if(i+1-k>=0)mp[(sum[i+1-k]+k)%k]--;
    mp[(sum[i]+k)%k]++;
    cnt+=mp[(sum[i+1]+k)%k];
  }
  cout<<cnt<<endl;
}

int main(){
	ios::sync_with_stdio(false);
  cin.tie(0);
	cout<<fixed<<setprecision(15);
	solve();
	return 0;
}
