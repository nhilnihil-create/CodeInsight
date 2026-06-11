#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

vector<int>A;
vector<int>a, b, c, d;
int ans = 0;
int n, m, q;
void dfs(int i) {
  if(i == n) {
    int tmp = 0;
    rep(i, q) {
      if(A[b[i]-1] - A[a[i]-1] == c[i]) {tmp += d[i];}
    }
    ans = max(tmp, ans);
  }
  else if(i == 0) {
    for(int j = 1; j <= m; j++) {
      A[0] = j;
      dfs(1);
    }
  }
  else {
    for(int j = A[i-1]; j <= m; j++) {
      A[i] = j;
      dfs(i+1);
    }
  }
}

int main() {
  cin >> n >> m >> q;
  a = b = c = d = vector<int>(q);
  rep(i, q) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  }
  //return 0;
  A = vector<int>(n, 0);
  dfs(0);
  cout << ans << endl;
}