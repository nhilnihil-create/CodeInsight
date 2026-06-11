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

signed main() {
  int N, M;
  cin >> N >> M;
  int sum = 0;
  for (int i = 0; i < M; i++) {
    int p; cin >> p;
    sum += p;
  }
  if (N-sum>=0) {
    cout << N-sum << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}