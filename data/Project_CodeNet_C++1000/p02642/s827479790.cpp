#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i < (n); i++)
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
using namespace std;
using ll = long long;
int INF = 1001001001;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  int m = 1000005;
  vector<int> cnt(m);
  for(int x :a) {
    if(cnt[x] != 0) {
      cnt[x] = 2;
      continue;
    }
    for(int i=x; i<m; i+=x) {
      cnt[i]++;
    }
  }
  int ans = 0;
  for(int x :a) {
    if(cnt[x] == 1) ans++; 
  }
  cout << ans << endl;
  return 0;
}