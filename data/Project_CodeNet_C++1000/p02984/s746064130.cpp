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

long long a[100000];

int main() {
  long long N;
  cin >> N;
  for(long long i = 0; i < N; i++) {
    cin >> a[i];
  }
  long long sum = 0;
  rep(i, N) {
    sum += a[i];
  }
  sum /= 2;
  // cout << sum << endl;
  long long temp = 0;
  for(long long i = 1; 2 * i - 1 <= N - 2; i++) {
    temp += a[2*i-1];
  }
  vector<long long> v;
  v.push_back(sum-temp);
  rep(i, N-1) {
    long long t = v.back();
    long long key = a[i] - t;
    v.push_back(key);
  }

  rep(i, v.size()) {
    v[i] *= 2;
    cout << v[i];
    if(i != v.size() - 1) cout << " ";
    else cout << endl;
  }
  return 0;
}