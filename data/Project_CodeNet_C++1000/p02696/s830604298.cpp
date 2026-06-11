#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

int main(){
  ll a, b, n;
  cin >> a >> b >> n;
  ll ans;
  if (b > n){
    ans = a * n / b - a * (n / b);
    cout << ans << endl;
    return 0;
  }
  else {
    n = b - 1;
    ans = a * n / b - a * (n / b);
    cout << ans << endl;
    return 0;
  }
  return 0;
}
