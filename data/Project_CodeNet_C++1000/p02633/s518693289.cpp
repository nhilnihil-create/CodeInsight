#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
constexpr int INF = 2e9;

ll gcd(ll a, ll b){
    if(b == 0)return a;
    return gcd(b,a%b);
}

ll lcm(ll c, ll d){
    ll g = gcd(c,d);
    ll l = c/g*d;//最小公倍数
    return l;
}

int main() {
  int x;
  cin >> x;
  int l = lcm(x, 360);
  cout << l / x << endl;
  return 0;
} 