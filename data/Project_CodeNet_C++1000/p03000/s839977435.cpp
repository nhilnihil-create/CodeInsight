#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
int main() {
  int n,x,ans = 1;
  cin >> n >> x;
  vi l(n),d(n+1,0);
  rep(i,n) cin >> l[i];
  for(int i=2; i<=n+1; i++){
    d[i-1] = d[i-2] + l[i-2];
    if(d[i-1] <= x){
      ans++;
    }
    else break;
  }
  cout << ans << endl;
}
