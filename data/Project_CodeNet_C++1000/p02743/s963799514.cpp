#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	ll a, b, c;
	cin >> a >> b >> c;
	if (a+b > c) {
		cout << "No" << endl;
		return 0;
	}
	ll p = c - a - b;
	p = p*p;
	ll q = 4*a*b;
	if (p > q) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
