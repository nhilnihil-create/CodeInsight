#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
// #define sort(a) sort(all(a))
using P = pair<int, int>;
using ll = long long;
using ld = long double;
typedef vector<int> vi;
int dx[4] = { 0, 1, 0,-1 };
int dy[4] = { 1, 0,-1, 0 };
const ll MOD = 1000000007;
#define PI 3.14159265358979323846264338327950L


using Graph = vector<vector<int>>;

signed main() {
    // 頂点数と辺数
    int N, M; cin >> N >> M;
    int H[N];
    int ans = 0;
    for (int i = 0; i < N; i++) cin >> H[i];
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        G[a-1].push_back(b-1);
        G[b-1].push_back(a-1);
    }
    for (int i = 0; i < N; i++) {
      bool flag = true;
      for (int j = 0; j < G[i].size(); j++) {
        if(H[i]<=H[G[i][j]]) flag=false;
      }
      if (flag) ans++;
    }
  cout << ans << endl;
  return 0;
}