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

long long gcd(long long &a, long long &b) {
  if(b == 0) return a;
  long long d;
  a = a % b;
  swap(a, b);
  d = gcd(a, b);
  return d;
}

int main() {
  long long x, y;
  cin >> x >> y;
  long long d;
  d = gcd(x, y);

  long long k = d;
  long long count = 0;
  for(long long i = 2; i * i <= k; i++) {
    if(d % i == 0) count++;
    while(d % i == 0) {
      d /= i;
    }
  }
  if(d != 1) count++;

  cout << count + 1 << endl; 

  return 0;
}