#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<cstring>
#include<math.h>
#include<map>
#include<bitset>
#include<iomanip>
#include<queue>
#include<functional>
#include<stack>
#include<tuple>
#include<cassert>
using namespace std;

#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using ll = long long;
using P = pair<long long, long long>;
using MATRIX = vector< vector<ll> >;

long long gcd(long long a, long long b) {
  if(b == 0) return a;
  long long d;
  a = a % b;
  swap(a, b);
  d = gcd(a, b);
  return d;
}

int main() {
  long long A, B, N;
  cin >> A >> B >> N;
  long long d = gcd(A, B);
  if(N >= B) {
    cout << (A * (B-1)) / B << endl;
    return 0;
  }
  long long ans = A * N / B;
  ans %= A;
  cout << ans << endl;

  return 0;
}