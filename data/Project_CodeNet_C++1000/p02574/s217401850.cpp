#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
using pii = pair<int, int>;
const int A = 1000005;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  int memo[1001000] = {};
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    memo[a[i]]++;
  }

  int gcdd = a[0];

  for (int i = 1; i < n; i++) {
    gcdd = __gcd(gcdd, a[i]);
  }
  // setwise coprime

  bool pairwise = true;

  for (int i = 2; i < A; i++) {
    int cnt = 0;
    for (int j = i; j < A; j += i) {
      cnt += memo[j];
    }
    if (cnt > 1) {
      pairwise = false;
      cout << (gcdd == 1 ? "setwise coprime" : "not coprime") << endl;
      return 0;
    }
  }

  cout << "pairwise coprime" << endl;
}