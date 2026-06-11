#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n;
  cin >> n;
  vi a(n), b(n-1);
  rep(i,n-1) cin >> b[i];
  a[0] = b[0];
  for(int i=1; i<n; i++){
    a[i] = b[i-1];
    if(a[i] > b[i] && i!=n-1) a[i] = b[i];
  }
  int ans = 0;
  rep(i,n) ans += a[i];
  cout << ans << endl;
}
