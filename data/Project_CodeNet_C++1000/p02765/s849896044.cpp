#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n); i++)
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
using namespace std;
using ll = long long;
int INF = 1001001001;

int main() {
  int n, r;
  cin >> n >> r;
  int ans = r;
  if(n < 10) ans += 100 * (10 - n);
  cout << ans << endl;
  return 0;
}