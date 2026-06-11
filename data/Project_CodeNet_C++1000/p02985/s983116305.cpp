#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <complex>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#ifndef LOCAL
#define debug(x) ;
#else
#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;

template <typename T1, typename T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &p) {
  out << "{" << p.first << ", " << p.second << "}";
  return out;
}

template <typename T>
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

int N, K;
vector<int> G[SIZE];

ll dfs(int now, int back = -1) {
  ll res = 1;

  ll x = K - (back != -1);

  for (int to : G[now]) {
    if (back == to) continue;
    x--;
    res = res * x % mod;
    res = res * dfs(to, now) % mod;
  }

  return res;
}

int main() {

  scanf("%d%d", &N, &K);

  for (int i=0; i<N-1; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--; b--;

    G[a].push_back(b);
    G[b].push_back(a);
  }

  cout << dfs(0) * K % mod << endl;

  return 0;
}
