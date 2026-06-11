#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double EPS = 1e-10;

int main() {
	ll n;
	cin >> n;
	int c = 0;
	ll x = 100;
	while (x < n) {
		c++;
		x += x / 100;
	}
	cout << c << endl;
}