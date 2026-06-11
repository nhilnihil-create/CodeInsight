#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;
using P = pair<int, int>;

int gcd(int a, int b) {
  if (a % b == 0) {
    return b;
  } else {
    return gcd(b, a % b);
  }
}

int gcds(vector<int> as) {
  int ans = as[0];
  for (int i = 1; i < (int)as.size(); i++) {
    ans = gcd(ans, as[i]);
  }
  return ans;
}

const int A = 1000005;
int main() {
  int n;
  cin >> n;
  vector<int> as(n);
  vector<int> cnts(A);
  rep(i, n) {
    cin >> as[i];
    cnts[as[i]]++;
  }
  bool isPair = true;
  for (int i = 2; i < A; i++) {
    int cnt = 0;
    for (int j = i; j < A; j += i) {
      cnt += cnts[j];
    }
    if (1 < cnt) {
      isPair = false;
    }
  }
  if (isPair) {
    cout << "pairwise coprime" << endl;
    return 0;
  }
  int g = gcds(as);
  if (g == 1) {
    cout << "setwise coprime" << endl;
    return 0;
  }

  cout << "not coprime" << endl;
  return 0;
}
