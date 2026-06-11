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
  long long N;
  string S;
  cin >> N >> S;
  vector<long long> v[3];
  char a[3] = {'R', 'G', 'B'};
  rep(i, N) {
    if(S[i] == a[0]) v[0].push_back(i);
    if(S[i] == a[1]) v[1].push_back(i);
    if(S[i] == a[2]) v[2].push_back(i);
  }
  long long ans = v[0].size() * v[1].size() * v[2].size();

  rep(i, N) {
    for(long long j = i+1; j< N; j++) {
      if(S[i] != S[j]) {
        if((i + j) % 2 == 0) {
          if(S[i] != S[(i+j)/2] && S[j] != S[(i+j)/2]) {
            ans--;
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}