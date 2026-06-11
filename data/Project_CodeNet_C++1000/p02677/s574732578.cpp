/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	cout << fixed << setprecision (18);
	ld a, b, h, w, y;
	cin >> a >> b >> h >> w;
	w /= 5;
	h += w / 12;
	ld d = abs (h - w);
	d *= 30;
	y = min(d, 360 - d);
//	cout << y << endl;
//	cout << cosl(3.141592653589793238462643383279502884197169399375105820974944 * y / 180.0) << endl;
	ld x = b * b + a * a - 2 * a * b * (cosl(3.141592653589793238462643383279502884197169399375105820974944 * y / 180.0) * 1.0);
	cout << sqrt (x);
}
