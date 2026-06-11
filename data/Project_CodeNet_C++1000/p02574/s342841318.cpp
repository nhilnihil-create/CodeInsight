#include <bits/stdc++.h>
#include <math.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define PI 3.14159265359
using namespace std;
using ll = long long;
using P = pair<int, int>;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int minPrimeFactor[1000001];
bool isPrime[1000001];
bool isExist[1000001];
int a[1000000];

int main() {
  rep(i, 1000001) { isPrime[i] = true; isExist[i] = false; }
  int n;
  cin >> n;
  rep(i, n) {
    cin >> a[i];
  }

  int ans = 0;

  /* preprocess */
  for (int i = 2; i <= 1000000; i++) {
    if (isPrime[i]) {
      for (int j = i; j <= 1000000; j += i) {
        if (isPrime[j]) {
          minPrimeFactor[j] = i;
          isPrime[j] = false;
        }
      }
    }
  }
  minPrimeFactor[1] = 1;

  rep(i, n) {
    vector<int> factors;
    factors.push_back(minPrimeFactor[a[i]]);
    int next = a[i] / minPrimeFactor[a[i]];
    while (next != 1) {
      //cout << "next " << next << endl;
      int factor = minPrimeFactor[next];
      if (factor != factors[factors.size() - 1]) {
        factors.push_back(factor);
      }
      next = next / factor;
    }
    rep(j, factors.size()) {
      if (isExist[factors[j]] && factors[j] != 1) ans = 1;
      else isExist[factors[j]] = true;
    }
  }

  if (ans == 0) {
    cout << "pairwise coprime" << endl;
    return 0;
  }

  int g = a[0];
  rep(i, n - 1) {
    g = gcd(a[i + 1], g);
  }
  if (g == 1) {
    cout << "setwise coprime" << endl;
    return 0;
  }

  cout << "not coprime" << endl;

  return 0;
}
/*
*/
