#include <bits/stdc++.h>
//#include <atcoder/all>
#define ll long long int
#define MOD 1000000007
#define P pair<ll,ll>
#define INF 1000000000000000000

//using namespace atcoder;
using namespace std;

int main(void){
  ll n;
  cin >> n;
  
  string s;
  cin >> s;
  
  vector<ll> rs(n + 1, 0), ws(n + 1, 0);
  for (ll i = 0; i < s.size(); i++){
    ws[i+1] = ws[i] + (s[i] == 'W' ? 1 : 0);
  }
  for (ll i = 0; i < s.size(); i++){
    rs[i+1] = rs[i] + (s[n-i-1] == 'R' ? 1 : 0);
  }

  ll ans = INF;
  for (ll i = 0; i <= n; i++){
    ans = min(ans, max(ws[i], rs[n-i]));
  }
  cout << ans << endl;

  return 0;
}
