#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int M;
  cin >> M;
  ll S = 0, D = 0;
  for (int i = 0; i < M; i++) {
    ll d, c;
    cin >> d >> c;
    S += d * c;
    D += c;
  }
  cout << D - 1 + (S - 1) / 9 << endl;
}