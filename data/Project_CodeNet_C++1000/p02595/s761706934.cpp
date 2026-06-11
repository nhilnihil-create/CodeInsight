#include <bits/stdc++.h>
#include <iostream>

#define ll long long

using namespace std;

int main() {
	int n;
	cin >> n;
	ll d;
	cin >> d;
	d *= d;
	int cnt = 0;
	for (int i=0; i<n; ++i) {
		ll a, b;
		cin >> a >> b;
		cnt += (a*a+b*b <= d);
	}
	cout << cnt;
}
