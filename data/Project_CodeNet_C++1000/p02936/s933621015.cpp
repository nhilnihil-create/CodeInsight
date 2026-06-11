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

vector<int> v[200000];
int visited[200000] = {0};
int ans[200000] = {0};

void dfs(int x) {
  visited[x] += 1;
  for(int i = 0; i < v[x].size(); i++) {
    int nx = v[x][i];
    if(visited[nx] == 0) {
      ans[nx] += ans[x];
      dfs(nx);
    }
  }
}

int main() {
  int N, Q;
  cin >> N >> Q;
  rep(i, N-1) {
    int x, y;
    cin >> x >> y;
    x--;y--;
    v[x].push_back(y);
    v[y].push_back(x);
  }
  rep(i, Q) {
    int s, t;
    cin >> s >> t;
    s--;
    ans[s] += t;
  }
  dfs(0);
  rep(i, N) {
    cout << ans[i];
    if(i != N-1) cout << " ";
    else cout << endl;
  }
  return 0;
}