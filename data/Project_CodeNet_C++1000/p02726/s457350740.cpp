#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rng(a) a.begin(),a.end()
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
  int n, x, y;
  cin >> n >> x >> y;
  if(x>y) swap(x,y);
  vector<int> ans(n);
  for(int i=1; i<n; i++) {
    for(int j=i+1; j<=n; j++) {
      int dis = min(j-i,abs(j-y)+abs(i-x)+1);
      ans[dis-1]++;
    }
  }
  rep(i,n-1) cout << ans[i] << endl;
  return 0;
}