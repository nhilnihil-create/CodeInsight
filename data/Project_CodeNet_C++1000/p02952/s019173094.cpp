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
  int N;
  cin >> N;
  if (N < 10) {
    cout << N << endl;
  } else if (N < 100) {
    cout << 9 << endl;
  } else if (N < 1000) {
    cout << (N - 99) + 9 << endl;
  } else if (N < 10000) {
    cout << (999 - 99) + 9 << endl;
  } else if (N < 100000) {
    cout << 9 + (999 - 99) + (N - 9999) << endl;
  } else {
    cout << 90909 << endl;
  }
}