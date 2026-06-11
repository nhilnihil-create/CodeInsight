#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n); i++)
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
using namespace std;
using ll = long long;
int INF = 1001001001;

int main() {
  int n;
  string s;
  cin >> n >> s;
  int ans = 0;
  rep(i, n-2) {
    if(s.substr(i,3) == "ABC") ans++;
  }
  cout << ans << endl;
  return 0;
}