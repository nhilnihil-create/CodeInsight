#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  bool all_neg = true, all_pos = true;
  for (ll i = 0; i < N; ++i) {
    cin >> A.at(i);
    if (A.at(i) < 0) {
      all_pos = false;
    }
    else if(A.at(i) > 0) {
      all_neg = false;
    }
  }
  sort(A.begin(), A.end());
  ll M = 0;
  if (all_pos) {
    M -= A.at(0);
    for (ll i = 1; i < N; ++i) {
      M += A.at(i);
    }
    cout << M << "\n";
    for (ll i = 1; i < N - 1; ++i) {
      cout << A.at(0) << ' ' << A.at(i) << "\n";
      A.at(0) -= A.at(i);
    }
    cout << A.at(N - 1) << ' ' << A.at(0) << "\n";
  }
  else if (all_neg) {
    for (ll i = 0; i < N - 1; ++i) {
      M -= A.at(i);
    }
    M += A.at(N - 1);
    cout << M << "\n";
    for (ll i = 0; i < N - 1; ++i) {
      cout << A.at(N - 1) << ' ' << A.at(i) << "\n";
      A.at(N - 1) -= A.at(i);
    }
  }
  else {
    for (ll i = 0; i < N; ++i) {
      M += abs(A.at(i));
    }
    cout << M << "\n";
    for (ll i = 1; i < N - 1; ++i) {
      if (A.at(i) < 0) {
        cout << A.at(N - 1) << ' ' << A.at(i) << "\n";
        A.at(N - 1) -= A.at(i);
      }
      else {
        cout << A.at(0) << ' ' << A.at(i) << "\n";
        A.at(0) -= A.at(i);
      }
    }
    cout << A.at(N - 1) << ' ' << A.at(0) << "\n";
  }
}
