#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n;
  cin >> n;
  vi a(n);
  rep(i,n) cin >> a[i];
  int mx, mx2;
  vi sa(n);
  rep(i,n) sa[i] = a[i];
  sort(sa.rbegin(),sa.rend());
  mx = sa[0];
  mx2 = sa[1];
  bool ok = false;
  int cnt = 0;
  rep(i,n){
    if(a[i] != mx) cout << mx << endl;
    else cout << mx2 << endl;
  }
}
