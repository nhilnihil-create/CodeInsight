#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

bool pos(string& S, ll start, ll goal)
{
  ll N = S.size();
  ll cnt = 0;
  for (ll i = start + 1; i < goal; ++i) {
    if (S[i] == '#') {
      cnt += 1;
      if (cnt == 2) {
        return false;
      }
    }
    else {
      cnt = 0;
    }
  }
  return true;
}

int main()
{
  ll N, A, B, C, D;
  cin >> N >> A >> B >> C >> D;
  A -= 1;
  B -= 1;
  C -= 1;
  D -= 1;
  string S;
  cin >> S;
  bool need_check = false;
  if (D < C) {
    need_check = true;
  }

  if (!need_check) {
    if (pos(S, A, C) && pos(S, B, D)) {
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }
  }
  else {
    bool ok = false;
    ll cnt = 0;
    for (ll i = B - 1; i <= D + 1; ++i) {
      if (S[i] == '.') {
        cnt += 1;
        if (cnt >= 3) {
          ok = true;
          break;
        }
      }
      else {
        cnt = 0;
      }
    }
    if (pos(S, A, C) && pos(S, B, D) && ok) {
      cout << "Yes" << endl;
    }
    else {
      cout << "No" << endl;
    }
  }

}

// 15 1 3 15 13
// ...#.#.#.#.#...
