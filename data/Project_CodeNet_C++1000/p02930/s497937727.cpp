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

vector<vector<int>>ans;
int n;

void func(int cnt,int i){
  rep(k,n-1){
    rep(l,ans[k].size()){
      if(ans[k][l]==0){
        ans[k][l]=i+2;
        --cnt;
        if(cnt==0)return;
      }
    }
  }
}

void solve(){
  cin>>n;
  ans.resize(n,vector<int>(n));
  rep(i,n-1){
    for(int j=i+1;j<n;++j){
      int x=i^j;
      rep(k,30){
        if(x&(1<<k)){
          ans[i][j]=k+1;
          break;
        }
      }
    }
  }
  rep(i,n-1){
    rep(j,ans[i].size()){
      if(ans[i][j]==0)continue;
      cout<<ans[i][j]<<" ";
    }
    cout<<"\n";
  }
}

int main(){
	ios::sync_with_stdio(false);
  cin.tie(0);
	cout<<fixed<<setprecision(15);
  solve();
	return 0;
}
