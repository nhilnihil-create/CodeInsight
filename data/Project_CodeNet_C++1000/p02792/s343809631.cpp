#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 100100100;
const int MOD = (int)1e9 + 7;
const double EPS = 1e-9;
int main() {
  ll N;
  cin >> N;
  vector<vector<int>> A(10, vector<int>(10, 0));
  ll ans = 0;
  for (int i = 1; i <= N; i++) {
    if (i % 10 == 0) continue;
    string s = to_string(i);
    int a = s[0] - '0';
    if (a == 0) continue;
    A[a][i % 10]++;
  }
  for (int i = 1; i <= N; i++) {
    if (i % 10 == 0) continue;
    string s = to_string(i);
    int a = s[0] - '0';
    if (a == 0) continue;
    ans += A[i % 10][a];
  }
  cout << ans << endl;
}