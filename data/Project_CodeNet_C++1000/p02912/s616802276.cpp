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

int main() {
  long long N, M;
  vector<long long> a;
  cin >> N >> M;
  rep(i, N) {
    long long temp;
    cin >> temp;
    a.push_back(temp);
  }

  long long sum = 0;
  rep(i, a.size()) {
    sum += a[i];
  }

  sort(a.begin(), a.end());
  long long ans = 0;
  rep(i, M) {
    long long key = a[a.size()-1];
    long long m = (key + 1) / 2;
    ans += m;
    key -= m;
    vector<long long>::iterator ind;
    ind = lower_bound(a.begin(), a.end(), key);
    a.pop_back();
    a.insert(ind, key);
  }

  // cout << ans << endl;

  ans = sum - ans;

  cout << ans << endl;

  return 0;
}