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
  ll N, M;
  cin >> N >> M;
  vector<ll> A(N), B(N);
  rep(i, N) cin >> A[i] >> B[i];

  vector<pair<ll, ll> > works;
  rep(i, N) works.push_back(make_pair(B[i], A[i]));

  sort(works.begin(), works.end());

  map<ll, bool> days;
  rep(i, M+1) days.insert(make_pair(i, true));

  ll reward = 0;
  for(int i = N-1; i >= 0; --i) {
    // cerr << works[i].first <<" "<< works[i].second << endl;
    ll daylimit = M - works.at(i).second;
    auto iter = days.upper_bound(daylimit);
    if (iter != days.begin()) {
      iter--;
      reward += works.at(i).first;
      days.erase(iter);
    }
  }
  
  cout << reward << endl;
  return 0;
}
