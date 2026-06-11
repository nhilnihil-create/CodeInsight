#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n); i++)
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
using namespace std;
using ll = long long;
int INF = 1001001001;

int main() {
  int n; int k;
  cin >> n >> k;
  int ans = 0;
  while(n) {
    n /= k;
    ans++;
  }
  cout << ans << endl;
  return 0;
}