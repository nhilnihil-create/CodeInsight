#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define reprev(i, n) for (int i = n - 1; i >= 0; i--)
using ll = long long;
using namespace std;
using P = pair<int, int>;


int main() {
  ll N, A, B;
  cin >> N >> A >> B;
  if ((B - A)%2 == 0) cout << (B - A)/2 << endl;
  else cout << (2*min(A-1, N-B)+1+B-A)/2 << endl;
}
