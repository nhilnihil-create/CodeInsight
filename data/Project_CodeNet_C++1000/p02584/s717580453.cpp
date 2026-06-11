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
  // std::cout << std::fixed << std::setprecision(15); //"for float-base
  // problem"
  ll X, K, D;
  cin >> X >> K >> D;
  if (X < 0) X *= -1;
  if ((X / D) >= K) {
    cout << X - (D * K) << endl;
  } else {
    if ((K - (X / D)) % 2 == 0) {
      cout << X % D << endl;
    } else {
      cout << abs((X % D) - D) << endl;
    }
  }
}