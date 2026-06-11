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
  ll N, K;
  cin >> N >> K;
  string S;
  cin >> S;

  char fromswap;
  char toswap; 
  if (S[0] == 'R') {
    fromswap = 'L';
    toswap = 'R';
  }
  else {
    fromswap = 'R';
    toswap = 'L';
  }
  ll swapcount = 0;
  ll swapl = 0, swapr = 0;
  rep (i, S.size()) {
    if (swapcount == K) break;
    if (S[i] == fromswap && swapl == 0) {
      swapl = i;
    }
    if (S[i] != fromswap && swapl != 0) {
      swapr = i;
      for (int j = swapl; j < swapr; ++j) {
        S[j] = toswap;
      }
      swapl = 0;
      swapr = 0;
      swapcount++;
    }
    if (i == S.size() - 1 && swapl != 0) {
      swapr = i + 1;
      for (int j = swapl; j < swapr; ++j) {
        S[j] = toswap;
      }
      swapl = 0;
      swapr = 0;
      swapcount++;
      break;
    }
  }
  ll happyness = 0;
  rep (i, S.size()) {
    if (S[i] == 'R' && i != S.size() - 1) {
      if (S[i+1] == 'R') happyness++;
    }
    else if (S[i] == 'L' && i != 0) {
      if (S[i-1] == 'L') happyness++;
    }
  }
  cout << happyness << endl;
  return 0;
}

