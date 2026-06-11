#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  // greedy
  int N, K;
  cin >> N >> K;
  int R, S, P;
  cin >> R >> S >> P;
  map<char, char> win{{'r', 'p'}, {'s', 'r'}, {'p', 's'}};
  map<char, int> score{{'r', R}, {'s', S}, {'p', P}};
  string T;
  cin >> T;
  char result[N];
  int ans = 0;
  rep(i, N) {
    char t = T[i];
    char w = win[t];
    if (i >= K && (result[i-K] == w)) {
      result[i] = 'a';
      continue;
    }
    ans += score[w];
    result[i] = w;
  }
  cout << ans << '\n';
  return 0;
}