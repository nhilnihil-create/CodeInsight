#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll N, A, B;
  cin >> N >> A >> B;
  ll res;
  if ((B-A) % 2 == 0) res = (B-A)/2;
  else res = min(A-1, N-B) + 1 + (B-A-1)/2;
  cout << res;
}
