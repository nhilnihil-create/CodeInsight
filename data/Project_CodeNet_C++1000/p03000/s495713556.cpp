#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
using namespace std;
using ll = long long;
using P = pair<int, int>;
 
int main() {
  int n, x;
  cin >> n >> x;
  vector<int> l(n);
  rep(i,n) cin >> l[i];
  vector<int> d(n+1,0);
  rep(i,n + 1){
    if(i == 0) continue;
    d[i] = d[i-1] + l[i-1];
  }
  int ans = 0;
  rep(i,n+1){
    if(d[i] <= x)ans++;
  }
  cout << ans << endl;
}
 