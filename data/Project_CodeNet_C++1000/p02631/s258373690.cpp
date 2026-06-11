#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<ll> a(N);
  ll bit = 0;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    bit = bit^a[i];
  }
  for (int i = 0; i < N; i++) cout << (a[i]^bit) << " ";
  cout << endl;
}
