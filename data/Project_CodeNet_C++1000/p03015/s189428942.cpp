#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for(int i = 0; i < n; i++)
#define MOD 1000000007

int main() {
  string s;
  cin >> s;

  int n = s.size();

  int cnt[n][2];
  rep(i,n) rep(j,2) cnt[i][j] = 0;
  for(int i = n-2; i >= 0; i--) {
    cnt[i][0] += cnt[i+1][0];
    cnt[i][1] += cnt[i+1][1];
    cnt[i][s[i+1] == '1'] += 1;
  }
  // rep(i,n) printf("%d %d\n",cnt[i][0],cnt[i][1]);

  ll p[n];
  p[0] = 1;
  rep(i,n-1) p[i+1] = p[i]*3%MOD;
  //rep(i,n) printf("%lld ",p[i]);
  //printf("\n");

  ll ans = 0;
  ll c = 1;
  rep(i,n) {
    if (s[i] == '1') {
      ans = (ans + c*p[n-1-i])%MOD;
      c = c*2%MOD;
    }
  }
  ans = (ans+c)%MOD;
  cout << ans << endl;


  return 0;
}