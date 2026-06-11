#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int main(){
  int n,p;
  cin >> n >> p;
  string s;
  cin >> s;

  if(p == 2 || p == 5) {
    ll ans = 0;
    for(int r = 0; r < n; r++){
      if((s[r] -'0')%p == 0) ans += r+1;
    }
    cout << ans << endl;
    return 0;
  }


  int c = 0;
  int fac = 1;
  vector<ll> val(p,0);
  val[0]++;
  rep(i,n){
    c += (s[n-1-i]-'0')*fac;
    c %= p;
    val[c]++;
    fac *= 10;
    fac %= p;
  }
  ll ans = 0;
  rep(i,p) ans += val[i]*(val[i]-1)/2;
  cout << ans << endl;
}
