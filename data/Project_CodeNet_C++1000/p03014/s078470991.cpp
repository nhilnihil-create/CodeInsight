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
  ll H, W;
  cin >> H >> W;
  vector<string> S(H);
  rep(i,H) cin >> S[i];

  vector<vector<ll> > latcount(H);
  rep(i, H) latcount[i].resize(W, 0);
  rep(i, H) {
    ll left = -1;
    rep(j, W + 1) {
      // j == W needs to be judged first so that j do not refer outside of range, S[i][W].
      if (j == W || S[i][j] == '#') {
        if (left != -1) {
          for (int k = left; k < j; ++k) {
            latcount[i][k] = j - left;
            // cerr << latcount[i][k] << endl;
          }
          left = -1;
        }
      }
      else if(S[i][j] == '.') {
        if (left == -1) left = j;
        // cerr << i <<" "<< j <<" "<< left << endl;
      }
    }
  }  

  vector<vector<ll> > loncount(H);
  rep(i, H) loncount[i].resize(W, 0);
  rep(j, W) {
    ll up = -1;
    rep(i, H + 1) {      
      // i == H needs to be judged first so that i do not refer outside of range, S[H][j].
      if ( i == H || S[i][j] == '#') {
        if (up != -1) {
          for (int k = up; k < i; ++k) {
            loncount[k][j] = i - up;
          }
          up = -1;
        }
      }
      else if(S[i][j] == '.') {
        if (up == -1) up = i;
      }
    }
  }  

  ll maxcount = 0;
  rep(i, H) {
    rep(j, W) {
      maxcount = max(maxcount, latcount[i][j] + loncount[i][j] - 1);
    }
  }
  cout << maxcount << endl;
  return 0;
}
