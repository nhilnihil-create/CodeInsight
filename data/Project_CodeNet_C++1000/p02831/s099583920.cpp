#include <bits/stdc++.h>
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
using P = pair<long long, long long>;

long long gcd(long long x, long long y) {
  if(y == 0) {
    return x;
  }
  long long z = x % y;
  return gcd(y, z);
}

int main() {
  long long a, b;
  cin >> a >> b;
  if(a < b) swap(a, b);
  long long ans = a * b / gcd(a, b);
  cout << ans << endl;
  return 0;
}