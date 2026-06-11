#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int MOD=1000000007;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  rep(j,k) {
    vector<int> b(n+1);
    rep(i,n) {
      int l=max(0,i-a[i]);
      int r=min(n,i+a[i]+1);
      b[l]++;  b[r]--;
    }
    rep(i,n) b[i+1]+=b[i];
    b.pop_back();
    if(a==b) break;
    a=b;
  }
  rep(i,n) cout << a[i] << " ";
  cout << endl;
  return 0;
}