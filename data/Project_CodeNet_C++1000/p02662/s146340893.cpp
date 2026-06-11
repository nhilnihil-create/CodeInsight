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
#define debug(...) ;
#else
#define debug(...) cerr << __LINE__ << " : " << #__VA_ARGS__ << " = " << _tostr(__VA_ARGS__) << endl;

template<typename T>
ostream &operator<<(ostream &out, const vector<T> &v);

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

void _tostr_rec(ostringstream &oss) {
  oss << "\b\b \b";
}

template<typename Head, typename... Tail>
void _tostr_rec(ostringstream &oss, Head &&head, Tail &&... tail) {
  oss << head << ", ";
  _tostr_rec(oss, forward<Tail>(tail)...);
}

template<typename... T>
string _tostr(T &&... args) {
  ostringstream oss;
  int size = sizeof...(args);
  if (size > 1) oss << "{";
  _tostr_rec(oss, forward<T>(args)...);
  if (size > 1) oss << "}";
  return oss.str();
}
#endif

#define mod 998244353 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 3010

ll dp[SIZE];

int main() {
  int N, S;

  scanf("%d%d", &N, &S);

  dp[0] = 1;

  for (int i = 0; i < N; i++) {
    int A;
    scanf("%d", &A);
    for (int j = S; j >= 0; j--) {
      if (j + A <= S)
        dp[j + A] = (dp[j + A] + dp[j]) % mod;
      dp[j] = dp[j] * 2 % mod;
    }
  }

  printf("%lld\n", dp[S]);

  return 0;
}