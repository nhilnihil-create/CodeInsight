#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int main(){
  int n;
  cin >> n;
  vector<int> a(n+1), b(n+1), c(n+1);

  rep(i,n+1) {
    if(i == 0) continue;
    cin >> a[i];
  }
  rep(i,n+1) {
    if(i == 0) continue;
    cin >> b[i];
  }
  rep(i,n+1) {
    if(i == 0) continue;
    cin >> c[i];
  }

  int ans = 0;
  rep(i,n+1){
    ans += b[a[i]];
    if(i == 0 || i == 1) continue;
    if(a[i] == a[i-1]+1) ans += c[a[i-1]];
    
  }
  cout << ans << endl;
}
