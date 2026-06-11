// #include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <map>
#include <math.h>
#include <algorithm> // std::sort, std::min, std::next_permutation, std::lower_bound
#include <iomanip> // std::setprecision
#include <cmath> // std::ceil
#include <numeric> // std::gcd, std::lcm
#include <limits> // std::numeric_limits<long int>::max()
#include <unordered_map>
#include <map>
#include <cmath> // std::atan2

using namespace std;
typedef long long ll;
#define INF 1999999999
#define MODA 1000000007 
#define rep(i,n) for (long long i = 0; i < (n); ++i)

int main() {
  ll N;
  cin >> N;
  vector<ll> a(N + 1);
  for (int i=1; i<N+1; ++i) cin >> a[i];

  ll M = 0;
  vector<ll> b(N + 1, 0);
  for (int i=N; i>0; --i) {
    ll j = i;
    ll sumj = 0;
    while (j < N+1) {
      sumj += b[j];
      j += i;
    }
    if (sumj%2 == a[i]) {
      b[i] = 0;
    }
    else {
      b[i] = 1;
      M += 1;
    }
  }
  
  cout << M << endl;
  for(int i=1; i<N+1; ++i) {
    if (b[i] == 1) cout << i <<" ";
  }
  cout << endl;

  return 0;
}
