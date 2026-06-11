#include <bits/stdc++.h>
#define REP(i, n) for (long long i = 0; i < (long long)n; i++)
//#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
using Pi = pair<int, int>;
using Pl = pair<ll, ll>;
using Vl = vector<ll>;
using vi = vector<int>;
using Graph = vector<vi>;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int K, N, C;
  int cnt = 0;
  string S;
  cin >> N >> K >> C >> S;
  vi table(N);
  vi L(K), R(K);
  REP(i, N) {
    if (S.at(i) == 'x') continue;
    L.at(cnt) = i;
    cnt++;
    if (K == cnt) {
      break;
    }
    i += C;
  }
  cnt = 0;
  for (int j = N - 1; j >= 0; j--) {
    if (S.at(j) == 'x') continue;
    R.at(K - cnt - 1) = j;
    cnt++;
    if (K == cnt) {
      break;
    }
    j -= C;
  }

  REP(i, K) {
    // cout << L.at(i) << " " << R.at(i) << endl;

    if (L.at(i) == R.at(i)) cout << L.at(i) + 1 << endl;
  }
}