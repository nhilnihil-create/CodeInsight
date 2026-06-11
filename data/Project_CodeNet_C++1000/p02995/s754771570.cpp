#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

ll gcd(ll a, ll b){//最大公約数
  if (b == 0){
    return a;
  }
  return gcd(b, a%b);
}

ll lcm(ll a, ll b){//最小公倍数
  ll c = gcd(a, b);
  return a / c * b;
}

int main(){
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  a--;
  ll e = lcm(c, d);
  ll ans = ((b-(b/c)) + (b-(b/d)) - (b-(b/e))) - ((a-(a/c)) + (a-(a/d)) - (a-(a/e)));
  cout << ans << endl;
  return 0;
}
