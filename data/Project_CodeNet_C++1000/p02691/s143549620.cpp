#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N;
vector<ll> A;
map<ll, ll> C;
ll Res;

int main() {
  cin >> N;
  A.resize(N);
  for (ll i = 0; i < N; ++i) {
    cin >> A[i];
    ++C[A[i] - i];
  }
  for (ll i = 0; i < N; ++i) {
    Res += C[-A[i] - i];
  }
  cout << Res << endl;
  return 0;
}
