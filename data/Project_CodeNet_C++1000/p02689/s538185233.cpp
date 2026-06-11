#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repc(i, a, b) for(int i = a; i <= (int)(b); i++)
#define ll long long
#define vec vector
#define ft first
#define sd second
#define all(vec) vec.begin(), vec.end()
typedef pair<int, int> P;
const int MOD = 1e9 + 7;
const int INF = 1001001001;


int main() {
  int n, m;
  cin >> n >> m;
  vec<int> h(n+1);
  vec<int> h_max(n+1, 0);
  repc(i, 1, n) cin >> h[i];
  repc(i, 1, m) {
    int a, b;
    cin >> a >> b;
    h_max[a] = max(h_max[a], h[b]);
    h_max[b] = max(h_max[b], h[a]);
  }
  int ans = 0;
  repc(i, 1, n) {
    if(h[i] > h_max[i]) ans++;
  }
  cout << ans << endl;
  return 0;
}