#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n,x,y;
  cin >> n >> x >> y;
  x--; y--;
  vector<int> ans(n+1,0);
  rep(i,0,n-1) rep(j,i+1,n) {
    if (i < x) {
      if (j <= x) {
        ans[j-i]++;
      } else if (x < j && j <= y) {
        ans[min(j-i,x+y-i-j+1)]++;
      } else {
        ans[x-i+j-y+1]++;
      }
    } else if (x <= i && i < y) {
      if (j <= y) {
        ans[min(j-i,i-x+y-j+1)]++;
      } else {
        ans[min(j-i,i-x+j-y+1)]++;
      }
    } else {
      ans[j-i]++;
    }
  }
  rep(i,1,n) {
    cout << ans[i] << endl;
  }
  return 0;
}
