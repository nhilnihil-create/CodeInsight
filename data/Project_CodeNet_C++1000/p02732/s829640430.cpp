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
using P = pair<long long, long long>;

int main() {
  long long a[200000];
  long long N;
  cin >> N;
  vector<long long> v;
  rep(i, N) {
    long long temp;
    cin >> temp;
    temp--;
    v.push_back(temp);
    a[temp]++;
  }
  long long sum = 0;
  rep(i, N) {
    sum += a[i] * (a[i]-1) / 2;
  }
  long long b[200000];
  rep(i, N) {
    b[i] = sum - a[i] + 1;
  }
  rep(i, v.size()) {
    cout << b[v[i]] << endl;
  }
  return 0;
}