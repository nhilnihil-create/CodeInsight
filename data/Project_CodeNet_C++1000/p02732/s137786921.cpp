#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i, n) for(int i = 0;i < (int)(n);i++)

int main() {
  int n;ll a, S = 0;
  cin >> n;
  map<int, ll> v;
  vector<int> A(n);
  REP(i, n) {
    cin >> A[i];
    v[A[i]]++;
  }
  for(auto p : v) {
    a = p.first;
    S += v[a] * (v[a] - 1) / 2;
  }
  REP(i, n) cout << S - v[A[i]] + 1 << endl;
}