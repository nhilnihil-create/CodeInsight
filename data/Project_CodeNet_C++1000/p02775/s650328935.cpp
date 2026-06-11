#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<long>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvb = vector<vector<bool>>;
using vvc = vector<vector<char>>;
using vvl = vector<vector<long>>;
using pii = pair<int, int>;
using pil = pair<int, long>;
using pll = pair<long, long>;
using vc = vector<char>;
#define fix20 cout << fixed << setprecision(20)
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define REP(i,s,t) for(int i=s; i<t; i++)
#define RNG(i,s,t,u) for(int i=s; i<t; i+=u)
#define MOD 1000000007
#define all(vec) vec.begin(), vec.end()

int main(){
  string s;
  cin >> s;
  int n = s.size();
  vi num(n);
  rep(i,n) num[i] = (s[i] - '0');
  vvl dp(2,vl(n));
  
  dp[0][n-1] = num[n-1];
  dp[1][n-1] = 10 - num[n-1];

  for(int i=n-2;i>=0;i--){
    dp[0][i] = min(dp[0][i+1] + num[i], dp[1][i+1] + num[i] + 1);
    dp[1][i] = min(dp[0][i+1] + 10 - num[i], dp[1][i+1] + 10 - (num[i] + 1));
  }
  cout << min(dp[0][0], dp[1][0] + 1) << endl;
}