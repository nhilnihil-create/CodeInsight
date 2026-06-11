#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using P = pair<int,int>;
using ll = long long;
static const int INF = 1000000000;
static const ll MOD = 1000000007;

ll gcd(ll a, ll b){return b!=0 ? gcd(b, a%b) : a;}
ll lcm(ll a, ll b){return a / gcd(a, b) * b;}

int main(){
	ll s;
  cin >> s;

  if(s == 1e18){
    cout << "0 0 1000000000 0 1000000000 1000000000" << endl;
    return 0;
  }

  ll x1, y1, x2, y2, x3, y3;
  x1 = 0;
  y1 = 0;
  x3 = 1;
  y3 = 1e9;
  
  // |x2 * y3 - x3 * y2| = s
  // (s + x3 * y2) mod y3 = 0
  // y3 - (s mod y3) = x3 * y2
  y2 = y3 - s % y3;
  x2 = (s + x3 * y2) / y3;

  cout << x1 << " " << y1 << " ";
  cout << x2 << " " << y2 << " ";
  cout << x3 << " " << y3 << endl;

	return 0;
}

