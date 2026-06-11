#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
  int N, K;
  cin >> N >> K;
  vector<ll> A(N);
  REP(i, N) cin >> A[i];
  while (K > 0) {
    vector<ll> imos(N + 10);
    REP(i, N) {

      imos[max<ll>(0, i - A[i])]++;
      imos[min<ll>(N+1, i + A[i] + 1)]--;
    }
    ll num = 0;
    ll n_num = 0;
    REP(i, N) {
      num += imos[i];
      A[i] = num;
      if (A[i] == N) n_num++;
    }
    if (n_num == N) break;
    K--;
  }
  REP(i, N) {
    cout << A[i];
    if (i != N - 1) cout << " ";
  }
  cout << endl;
}