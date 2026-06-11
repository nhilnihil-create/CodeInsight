#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <bitset>
#include <complex>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <cassert>
#include <functional>

typedef long long ll;
using namespace std;

#ifndef LOCAL
#define debug(x) ;
#else
#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;

template<typename T1, typename T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &p) {
  out << "{" << p.first << ", " << p.second << "}";
  return out;
}

template<typename T>
ostream &operator<<(ostream &out, const vector<T> &v) {
  out << '{';
  for (const T &item : v) out << item << ", ";
  out << "\b\b}";
  return out;
}
#endif

#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 200010

ll power(ll k, ll n, int M) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * k % M;
    k = k * k % M;
    n /= 2;
  }
  return res;
}

int main() {
  int N, P, d;

  scanf("%d%d", &N, &P);

  ll ans = 0;

  if (P == 2 || P == 5) {
    for (int i = 0; i < N; i++) {
      scanf("%1d", &d);
      if (d % P == 0) ans += i + 1;
    }
  } else {
    int now = 0;
    int inv10 = power(10, P - 2, P);
    int t = 1;

    map<int, int> counter;
    counter[0]++;

    for (int i = 0; i < N; i++) {
      scanf("%1d", &d);
      now = (now * 10 + d) % P;
      ans += counter[now * t % P];
      counter[now * t % P]++;
      t = t * inv10 % P;
    }
  }
  cout << ans << endl;

  return 0;
}
