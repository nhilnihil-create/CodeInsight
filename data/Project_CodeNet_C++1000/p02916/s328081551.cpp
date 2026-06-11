#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int MOD=1000000007;

int main() {
  int n;
  cin >> n;
  vector<int> a(n), c(n-1);
  rep(i,n) {
    int x;  cin >> x;
    a[i]=x-1;
  }
  int ans=0;
  rep(i,n) {
    int b; cin >> b;
    ans+=b;
  }
  rep(i,n-1) cin >> c[i];
  rep(i,n-1) {
    if(a[i]+1==a[i+1]) ans+=c[a[i]];
  }

  cout << ans << endl;
}