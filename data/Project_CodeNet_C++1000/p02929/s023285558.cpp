#include <iostream>
#include <cstdio>
#define N 200005
using namespace std;

typedef long long ll;
ll M = 1e9 + 7;
ll n, ans = 1, c, b[N];
string a;
int main()
{
	ll i;
	cin >> n >> a;
	if (a[0] == 'W') {puts("0"); return 0;}
	b[0] = 1;
	for (i = 1; i < n * 2; i++) {
        if (a[i] != a[i - 1]) b[i] = b[i - 1];
        else b[i] -= b[i - 1];
	}
	for (i = 0; i < n * 2; i++) {
		if (b[i] < 0) ans = ans * c % M;
		c += b[i];
		if (c < 0) {puts("0"); return 0;}
	}
	if (c != 0) {puts("0"); return 0;}
	for (i = 1; i <= n; i++) ans = ans * i % M;
    cout << ans << endl;
    return 0;
}