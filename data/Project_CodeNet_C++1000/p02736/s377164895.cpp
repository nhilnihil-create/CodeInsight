#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;
ll n, m, s, cnt, a[1000005];
string ta;
int main()
{
	ll i, j, t;
	cin >> n;
	cin >> ta;
	for (i = 0; i < n; i++) {
		a[i] = ta[i] - '1';
		if (a[i] == 1) cnt++;
	}
	for (i = 0; i < n; i++) {
		j = n - i - 1;
		t = (i ^ j);
		if (t == n - 1) s += a[i];
	}
	if (s % 2) {
		cout << 1;
		return 0;
	}
	if (cnt > 0) {
		cout << 0;
		return 0;
	}
	for (i = 0; i < n; i++) {
		a[i] /= 2;
	}
	s = 0;
	for (i = 0; i < n; i++) {
		j = n - i - 1;
		t = (i ^ j);
		if (t == n - 1) s += a[i];
	}
	if (s % 2) cout << 2;
	else cout << 0;
    return 0;
}
