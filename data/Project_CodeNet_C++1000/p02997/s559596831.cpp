#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n,k;
  cin >> n >> k;

  if(k>(n-1)*(n-2)/2){
    cout << -1 << endl;
    return 0;
  }

  int m = n-1;
  vector<int> ans[n];
  rep(i,n-1) ans[0].emplace_back(i+1);

  int cnt = (n-1)*(n-2)/2 - k;
  for(int i=1; i<n-1; ++i) for(int j = i+1; j<n; ++j){
    if(cnt<=0) break;
    ++m;
    ans[i].emplace_back(j);
    --cnt;
  }
  cout << m << endl;
  rep(i,n)rep(j,ans[i].size()) cout << i+1 << " " << ans[i][j]+1 << endl;
}
