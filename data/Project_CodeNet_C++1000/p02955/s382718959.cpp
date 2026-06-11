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
#define SIZE 1010

template <typename T>
vector<T> divisor(T n){
  vector<T> res, res2;
  for(T i=1; i*i<=n; i++){
    if(n%i == 0){
      res.push_back(i);
      if(i*i < n) res2.push_back(n/i);
    }
  }

  reverse(res2.begin(), res2.end());
  res.insert(res.end(), res2.begin(), res2.end());

  return res;
}


int main() {
  int N, K, A[SIZE], B[SIZE];
  int sum = 0;

  cin >> N >> K;

  for (int i=0; i<N; i++) {
    cin >> A[i];
    sum += A[i];
  }

  auto vec = divisor(sum);

  int ans = 1;

  for (auto v : vec) {
    ll sumU = 0, sumD = 0;

    for (int i=0; i<N; i++) {
      sumD += A[i] % v;
      B[i] = A[i] % v;
    }

    sort(B, B+N, greater<int>());

    ll res = sumD;

    for (int i=0; i<N; i++) {
      sumD -= B[i];
      sumU += (v - B[i]) % v;
      res = min(res, max(sumD, sumU));
    }

    if (res <= K) {
      ans = max(ans, v);
    }
  }

  cout << ans << endl;

  return 0;
}
