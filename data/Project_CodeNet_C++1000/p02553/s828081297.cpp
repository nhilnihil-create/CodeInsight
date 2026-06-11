#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  	ll a, b, c, d;
  	cin >> a >> b >> c >> d;
  
  	ll ac=a*c, ad=a*d, bc=b*c, bd=b*d;
  	ll ans = max(max(ac, ad), max(bc, bd));
  	cout << ans << endl;
  	return 0;  
}
