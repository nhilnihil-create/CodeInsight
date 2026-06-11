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
  string S;
  vector<long long> v;
  cin >> S;
  long long N = S.size();
  long long key = 0;
  char k[2] = {'R', 'L'};
  rep(i, N) {
    if(S[i] == k[key]) continue;
    else {
      v.push_back(i-1);
      key = key ^ 1;
    }
  }
  v.push_back(N-1);
  long long ans[100000] = {0};
  rep(i, v.size()) {
    if(i % 2 == 1) continue;
    if(i == 0) {
      ans[v[i]] += (v[i] + 2) / 2;
      ans[v[i]] += (v[i+1]-v[i]) / 2;
      ans[v[i]+1] += (v[i] + 1) / 2;
      ans[v[i]+1] += (v[i+1]-v[i]+1) / 2;
    } else {
      ans[v[i]] += (v[i]-v[i-1]+1) / 2;
      ans[v[i]] += (v[i+1]-v[i]) / 2;
      ans[v[i]+1] += (v[i]-v[i-1]) / 2;
      ans[v[i]+1] += (v[i+1]-v[i]+1) / 2;
    }
  }
  rep(i, N) {
    cout << ans[i];
    if(i != N-1) cout << " ";
    else cout << endl;
  }
  return 0;
}