#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const int MOD = (int)1e9 + 7;
const double PI = 3.14159265358979323846;
template <class T, class U>
void chmin(T& t, const U& u) {
  if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
  if (t < u) t = u;
}

const int MX = 1000005;
int main(void) {
  int N;
  cin >> N;
  vector<int> A(N);
  vector<int> c(MX, 0);
  rep(i, N) cin >> A[i], c[A[i]]++;
  bool pairwise = true;
  for (int i = 2; i < MX; i++) {
    int cnt = 0;
    for (int j = i; j < MX; j += i) {
      cnt += c[j];
    }
    if (cnt > 1) pairwise = false;
  }
  if (pairwise) {
    cout << "pairwise coprime" << endl;
    return 0;
  }
  int g = 0;
  rep(i, N) g = gcd(g, A[i]);
  if (g == 1) {
    cout << "setwise coprime" << endl;
    return 0;
  }
  cout << "not coprime" << endl;
  return 0;
}