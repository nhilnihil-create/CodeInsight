#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef pair<int, int> P;

const long double EPS = 1e-10;
const long long INF = 1e18;
const int MOD = (int)1e9 + 7;
const long double PI = acos(-1.0L);

const int MAX_N = 200050;

int main() {  // TODO
  ll N;
  vector<ll> AN(MAX_N);
  cin >> N;
  vector<ll> A(N);
  rep(i, N) {
    cin >> A[i];
    AN[A[i]]++;
  }
  ll base = 0;
  rep(i, MAX_N) {
    if (AN[i] < 2) continue;
    base = base + (AN[i] * (AN[i] - 1) / 2);
  }

  rep(i, A.size()) {
    ll a = A[i];
    if (AN[a] < 2) {
      cout << base << endl;
      continue;
    }
    if (AN[a] == 2) {
      cout << base - 1 << endl;
      continue;
    }
    ll diff = ((AN[a]) * (AN[a] - 1)) - ((AN[a] - 1) * (AN[a] - 2));
    cout << base - (diff / 2) << endl;
  }
  return 0;
}
