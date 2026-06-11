#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n); i++)
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
using namespace std;
using ll = long long;
int INF = 1001001001;

int main() {
  int n;
  cin >> n;
  vector<int> d(n);
  rep(i,n) cin >> d[i];
  int ans = 0;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      if(j <= i) continue;
        ans += d[i]*d[j];
    }
  }
  cout << ans << endl;
  return 0;
}