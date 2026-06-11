#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)
#define pb push_back
using ll = long long;
using P = pair<ll,ll>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

/*
 string -> int : stoi(S);
 int -> string : to_string(N);
 Sのn文字以降をm文字取り出す : S.substr(n,m)
cout << fixed << setprecision(2) << 3.14 << endl; //3.1

 int: -2,147,483,648 ～ 2,147,483,647 (2×10^9)
 ll: -9,223,372,036,854,775,808 ~ 9,223,372,036,854,775,807 (9×10^18)

*/

int main() {

  ll n, count=0, ans=0;
  string s;
 
  cin >> n;

  vector<P> a;

  rep(i,n){
    cin >> count;
    a.pb(make_pair(count,i+1));
  }

  sort( a.rbegin(), a.rend());

  
  vector<vector<ll>> dp(n+1,vector<ll>(n+1));
  dp[0][0]=0;//[左][右]
  rep2(i,n){
    dp[i][0]=dp[i-1][0] + a[i-1].first*(a[i-1].second - i);
    dp[0][i]=dp[0][i-1] + a[i-1].first*((n-i+1) - a[i-1].second);
  }
  
  rep2(i,n){
    rep2(l,n){
      if(i+l>n) continue;

      dp[i][l]=max(dp[i][l-1] + a[i+l-1].first*((n-l+1) - a[i+l-1].second),
                   dp[i-1][l] + a[i+l-1].first*(a[i+l-1].second - i));
    }
  } 

  rep(i,n+1){
    chmax(ans,dp[i][n-i]);
  }

  cout << ans << endl;
}