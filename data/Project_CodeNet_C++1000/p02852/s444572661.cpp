#include <bits/stdc++.h>
using namespace std;
#ifdef DEBUG
#define FPEN freopen("in.txt", "r", stdin);
#else
#define FPEN
#endif
const int maxn = 200009;
typedef long long i64;
typedef pair<i64, i64> pi64;
typedef pair<int, int> pi;
const i64 MOD = 119 << 23 | 1;
class {
 public:
  struct NODE {
    int turn, pos;
    NODE(int a, int b) : turn(a), pos(b) {}
    bool operator<(const NODE &p) const {
      if (turn == p.turn)
        return pos > p.pos;
      return turn > p.turn;
    }
  };
  int nxt[maxn];
  void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    priority_queue<NODE> que;
    que.emplace(0, n);
    for (int i = n - 1; i >= 0; --i) {
      if (s[i] == '1')
        continue;
      while (que.size() && que.top().pos - i > m) {
        que.pop();
      }
      if (!que.size()) {
        cout << -1;
        return;
      }
      nxt[i] = que.top().pos;
      que.emplace(que.top().turn + 1, i);
    }
    int b = 0;
    while (b != n) {
      cout << nxt[b] - b << ' ';
      b = nxt[b];
    }
    cout << endl;
  }
} NSPACE;
int main() {
  FPEN;
  ios_base::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  NSPACE.solve();
}