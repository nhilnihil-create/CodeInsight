#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for(int i = 0; i < n; i++)

int main() {
  int n;
  cin >> n;
  int w[n];
  rep(i,n) cin >> w[i];
  int s = 0;
  rep(i,n) s += w[i];
  int c = 0;
  int ans = 100000;
  rep(i,n-1) {
    c += w[i];
    ans = min(ans,abs(s-c-c));
  }
  cout << ans << endl;
  return 0;
}