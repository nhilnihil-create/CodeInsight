#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); i++)
using namespace std;

int main() {
  int a, b, m;
  cin >> a >> b >> m;
  vector<int> A(a), B(b);
  rep(i,a) cin >> A[i];
  rep(i,b) cin >> B[i];
  
  int amin = 1001001001, bmin = 1001001001;
  rep(i,a) amin = min(amin,A[i]);
  rep(i,b) bmin = min(bmin,B[i]);
  int ans = amin + bmin;
  
  rep(i,m) {
    int x, y, c;
    cin >> x >> y >> c;
    x--;
    y--;
    ans = min(ans,A[x]+B[y]-c);
  }
  
  cout << ans << endl;
}