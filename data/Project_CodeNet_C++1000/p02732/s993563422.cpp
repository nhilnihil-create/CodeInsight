#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i, n) for(int i = 0;i < (int)(n);i++)

int main() {
  int n;
  ll S = 0;
  cin >> n;
  vector<ll> A(n), v(200001, 0);
  REP(i, n) {
    cin >> A[i];
    v[A[i]]++;
  }
  REP(i, 200000) S += v[i + 1] * (v[i + 1] - 1) / 2;
  REP(i, n) cout << S - v[A[i]] + 1 << endl;
}