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

long long N;
vector<P> v;

int main() {
  cin >> N;
  rep(i, N) {
    long long a, b;
    cin >> a >> b;
    v.push_back(make_pair(b, a));
  }
  sort(v.begin(), v.end());
  long long sum = 0;
  rep(i, v.size()) {
    sum += v[i].second;
    if(sum > v[i].first) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}