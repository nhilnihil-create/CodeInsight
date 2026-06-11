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

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using ll = long long;
using P = pair<int, int>;
using MATRIX = vector< vector<ll> >;

int N, M, Q;
int a[50], b[50], c[50], d[50];
int ar[20];
int ans = 0;

void dfs(int p, int q) {
  if(p == N && q == M-1) {
    int key = 1;
    int temp = 0;
    vector<int> v;
    rep(i, N + M - 1) {
      if(ar[i] == 1) key++;
      else {
        v.push_back(key);
      }
    }
    // rep(i, v.size()) {
    //   cout << v[i] << " ";
    // }
    // cout << endl;
    rep(i, Q) {
      if(v[b[i]] - v[a[i]] == c[i]) {
        temp += d[i];
      }
    }
    // cout << temp << endl;
    ans = max(ans, temp);
  } else if(p == N) {
    ar[p+q] = 1;
    dfs(N, q + 1);
  } else if(q == M-1) {
    ar[p+q] = 0;
    dfs(p+1, M-1);
  } else {
    ar[p+q] = 0;
    dfs(p+1, q);
    ar[p+q] = 1;
    dfs(p, q+1);
  }
}

int main() {
  cin >> N >> M >> Q;
  rep(i, Q) {
    cin >> a[i] >> b[i]>> c[i] >> d[i];
    a[i]--;b[i]--;
  }

  dfs(0, 0);

  cout << ans << endl;

  return 0;
}