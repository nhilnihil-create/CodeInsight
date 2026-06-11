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

#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 200010

pair<int, int> p[SIZE];
vector<int> a, b;

pair<int, int> calc(int X) {
  return {a[X - 1], b[X - 1]};
}

int main() {
  int N;

  scanf("%d", &N);

  for (int i = 0; i < N; i++) {
    int A, B;
    scanf("%d%d", &A, &B);
    p[i] = {A, B};
    a.push_back(A);
    b.push_back(B);
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  if (N % 2 == 1) {
    auto r = calc((N + 1) / 2);
    debug(r);
    printf("%d\n", r.second - r.first + 1);
  } else {
    auto r1 = calc(N / 2);
    auto r2 = calc(N / 2 + 1);
    debug(r1, r2);
    printf("%d\n", (r1.second + r2.second) - (r1.first + r2.first) + 1);
  }

  return 0;
}