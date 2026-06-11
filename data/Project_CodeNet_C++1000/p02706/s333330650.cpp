#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ll N,M;
  cin >> N >> M;
  ll sum = 0;
  for (ll i = 0; i < M; i++) {
    int a;
    cin >> a;
    sum += a;
  }

  if (N >= sum) {
    cout << (N - sum) << endl;
  } else {
    cout << "-1" << endl;
  }
  return 0;
}