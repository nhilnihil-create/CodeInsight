#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;


int main() {
  int n;
  cin >> n;
  int num[10][10];
  memset(num,0,sizeof(num));
  for(int i = 1; i <= n; i++) {
    string s = to_string(i);
    num[s[0]-'0'][i%10]++;
  }
  ll ans = 0;
  for(int i = 1; i <= 9; i++) {
    for(int j = 1; j <= 9; j++) ans += num[i][j]*num[j][i];
  }
  cout << ans << endl;
  return 0;
}