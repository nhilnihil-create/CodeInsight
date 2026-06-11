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

void solve(){
  int n,m;
  cin>>n>>m;
  vector<int>s(n),t(m);
  rep(i,n)cin>>s[i];
  rep(i,m)cin>>t[i];
  vector<vector<ll>>dp(n+1,vector<ll>(m+1));
  vector<vector<ll>>sum(n+1,vector<ll>(m+1));
  rep(i,n){
    rep(j,m){
      if(s[i]==t[j]){
        dp[i+1][j+1]+=sum[i][j]+1;
      }
      dp[i+1][j+1]%=mod;
      sum[i+1][j+1]=(sum[i][j+1]+sum[i+1][j]-sum[i][j]+dp[i+1][j+1]+mod)%mod;
    }
  }
  cout<<(sum[n][m]+1)%mod<<endl;
}

int main(){
	ios::sync_with_stdio(false);
  cin.tie(0);
	cout<<fixed<<setprecision(15);
	solve();
	return 0;
}
