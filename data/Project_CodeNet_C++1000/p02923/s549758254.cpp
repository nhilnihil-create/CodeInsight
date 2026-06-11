#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n); i++)
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
using namespace std;
using ll = long long;
int INF = 1001001001;

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  rep(i, n) cin >> h[i];
  int before = 0;
  int ans = 0;
  for(int i=n-2; i>=0; i--) {
    if(h[i] >= h[i+1]) before++;
    else before =0;
    ans = max(before, ans);
  }
  cout << ans << endl;
  return 0;
}