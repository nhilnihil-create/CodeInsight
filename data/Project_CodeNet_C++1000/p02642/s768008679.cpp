#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repc(i, a, b) for (int i = a; i <= (int)(b); i++)
#define ll long long
#define vec vector
#define ft first
#define sd second
#define all(vec) vec.begin(), vec.end()
typedef pair<int, int> P;
const int MOD = 1e9 + 7;
const int INF = 1001001001;
const int dx[4] = {1, 0,-1, 0};
const int dy[4] = {0, 1, 0,-1};

const int M = 1000005;

int main() {
  int n;
  cin >> n;
  vec<int> a(n);
  rep(i, n) cin >> a[i];
  vec<int> cnt(M);
  for(int x : a) {
    if(cnt[x] != 0) {
      cnt[x] = 2;
      continue;
    }
    for(int i = x; i < M; i += x) cnt[i]++;
  }
  int ans = 0;
  for(int x : a) {
    if(cnt[x] == 1) ans++;
  }
  cout << ans << endl;
  return 0;
}