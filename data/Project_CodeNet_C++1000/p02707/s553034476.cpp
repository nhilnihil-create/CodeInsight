#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n;
  cin >> n;
  vi a(n-1), ans(n,0);
  rep(i,n-1) {
    cin >> a[i];
    ans[a[i]-1] ++;
  }
  rep(i,n) cout << ans[i] << endl;
}
