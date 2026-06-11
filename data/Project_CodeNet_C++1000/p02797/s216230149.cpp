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
  ll N, K, S;
  cin >> N >> K >> S;
  if (S != 1e+9) {
    REP(i, K ) cout << S << " ";
    for (int i = K ; i < N; i++) {
      cout << S + 1<<" ";
    }
   
  } else {
    REP(i, K ) cout << S << " ";
    for (int i = K ; i < N; i++) {
      cout << 1<< " ";
    }
  }
  cout << endl;
}