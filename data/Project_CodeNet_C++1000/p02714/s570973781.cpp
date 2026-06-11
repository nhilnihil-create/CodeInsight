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
  long long r[3][4001] = {0};
  vector<long long> v[3];
  rep(i, N) {
    if(S[i] == 'R') {
      r[0][i+1] = 1; 
      v[0].push_back(i);
    }
    if(S[i] == 'G') {
      r[1][i+1] = 1;
      v[1].push_back(i);
    } 
    if(S[i] == 'B') {
      r[2][i+1] = 1; 
      v[2].push_back(i);
    }
  }
  rep(i, N) {
    r[0][i+1] += r[0][i];
    r[1][i+1] += r[1][i];
    r[2][i+1] += r[2][i];
  }

  char a[3] = {'R', 'G', 'B'};
  long long ans = 0;

  rep(i, 3) {
    rep(j, 3) {
      if(i == j) continue;
      rep(k, 3) {
        if(k == i || k == j) continue;
        rep(p, v[i].size()) {
          rep(q, v[j].size()) {
            if(v[i][p] >= v[j][q]) continue;
            ans += r[k][v[j][q]] - r[k][v[i][p]+1];
            // cout << i << " " << j << endl;
            // cout << a[i] << " " << a[j] << " " << a[k] << " " << v[i][p] << " " << v[j][q] << endl;
            // cout << ans << endl;
            if((v[j][q]+v[i][p])%2 == 0 && S[(v[j][q]+v[i][p]) / 2] == a[k]) {
              ans -= 1;
            }
            // cout << ans << endl;
          }
        }
      }
    }
  }
  cout << ans << endl;

  // rep(i, 3) {
  //   rep(j, N+1) {
  //     cout << r[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  return 0;
}