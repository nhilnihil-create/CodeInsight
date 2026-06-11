#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<vector<int>> Matrix;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()

ll gcd(ll a, ll b){
  if(a % b == 0) return b;
  else return gcd(b, a%b);
}

//最小公倍数
ll lcm(ll a, ll b){
  ll g = gcd(a, b);
  return a / g * b;
}

int f(ll x){
  int res = 0;
  while (x % 2 == 0){
    res++;
    x /= 2;
  }
  return res;
}

int main(){
  int n, m;
  cin >> n >> m;
  vector<ll> a(n);
  rep(i, n) {
    cin >> a[i];
    a[i] /= 2; 
  }

  ll x = 1;
  rep(i, n){
    x = lcm(x, a[i]);
    if (f(x) != f(a[i])){
      cout << 0 << endl;
      return 0;
    }
  }
  ll ans = (m / x + 1) / 2;
  cout << ans << endl;
}
