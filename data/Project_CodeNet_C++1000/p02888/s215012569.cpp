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

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
using P = pair<int, int>;

int main() {
  int N;
  int a[2000];
  cin >> N;
  rep(i, N) {
    cin >> a[i];
  }
  sort(a, a+N);
  vector<pair<int, P>> b;
  // int b[2000][2000];
  rep(i, N) {
    for(int j = i + 1; j < N; j++) {
      b.push_back({a[j]-a[i], {i, j}});
      // b[i][j] = a[j] - a[i];
    }
  }

  int ans = 0;

  rep(i, b.size()) {
    int key = b[i].first;
    int ni = b[i].second.first;
    int nj = b[i].second.second;
    int ind = upper_bound(a+ni+1, a+nj, key) - a;
    int temp = nj - ind;
    ans += temp;
  }

  cout << ans << endl;

  return 0;
}