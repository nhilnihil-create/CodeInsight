#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int MOD=1000000007;

int main() {
  int n;
  cin >> n;
  char s[n];
  char t[n];
  rep(i,n) cin >> s[i];
  rep(i,n) cin >> t[i];
  rep(i,n) cout << s[i] << t[i];
  cout << endl;
}
