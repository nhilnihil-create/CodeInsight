#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
const long long INF = 1ll << 60;



int main() {
  ll a, b, k; cin >> a >> b >>k;
  ll x = min(a,k);
  a-=x;
  k-=x;
  x = min(b,k);
  b-=x;

  cout << a << " " << b << endl;
  
	return 0;
}

