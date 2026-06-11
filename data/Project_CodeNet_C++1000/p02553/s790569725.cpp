#include <bits/stdc++.h>

#define ll long long
using namespace std;

int main() {
	ll a,b,c,d; cin >> a >> b >> c >> d;
  	
  	ll x = a*c, y = b*d, x1 = a*d, y1 = b*c;
  	cout << max(max(x,y), max(x1,y1));
  	return 0;
}