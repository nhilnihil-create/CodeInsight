#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep2(i,a,b) for(int i=(a);i<(b);++i)

template<class T> inline void chmin(T& a, T b) {if (a > b) a = b;}
template<class T> inline void chmax(T& a, T b) {if (a < b) a = b;}


ll const mod = 1e9+7;
int main() {
  int N;
  string S;
  cin >> S;
  N = S.size();
  vector<vector<ll>> memo(N+1,vector<ll>(2,0));
  memo[0][0] = 1;
  rep2(i,1,N+1) {
    auto t = S[i-1];
    if (t=='0') {
      memo[i][0] = memo[i-1][0]%mod;
      memo[i][1] = memo[i-1][1]*3%mod;
    }
    else {
      memo[i][0] = memo[i-1][0]*2%mod;
      memo[i][1] = (memo[i-1][0] + memo[i-1][1]*3)%mod;
    }
  }
  cout << (memo[N][0] + memo[N][1])%mod << endl;
}