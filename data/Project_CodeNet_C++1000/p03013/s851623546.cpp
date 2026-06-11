#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(obj) (obj).begin(), (obj).end()
#define bit(n) (1LL << (n))

typedef long long ll;

template<class T> inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const long long INF = 1LL << 60;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n,m; cin>>n>>m;
  
  vector<bool> issafe;
  issafe.assign(n+1, true);
  
  rep(i,m) {
    int a; cin>>a;
    issafe[a] = false;
  }
  
  vector<int> dp(n+1, 0);
  
  dp[0] = 1;
  if(issafe[1]) dp[1] = 1;
  
  for (int i = 2; i < n+1; ++i) {
    if(issafe[i-1]) dp[i] += dp[i-1];
    if(issafe[i-2]) dp[i] += dp[i-2];
    
    dp[i] = dp[i]%1000000007;
  }
  
  cout<<dp[n];
  
  return 0;
}

