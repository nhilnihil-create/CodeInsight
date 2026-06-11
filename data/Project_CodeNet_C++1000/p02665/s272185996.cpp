
#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read() {
	char c = getchar();
	ll x = 0, f = 1;
	for (; !isdigit(c); c = getchar())
		if (c == '-')
			f = -1;
	for (; isdigit(c); c = getchar())
		x = x * 10 + c - 48;
	return x * f;
}
const int N = 1e5 + 5;
ll a[N] = { 0 }, s[N], b[N] = { 0 }, n, n2, maxi, sum, flag = 0;
int main()
{
	n = read();
	for (ll i = 0; i <= n; ++i)
		a[i] = read();
	s[0] = a[0];
	if (n == 0)
		if (a[0] == 1){
			cout << 1 << endl;
			return 0;
		}
		else{
			printf("-1");
			return 0;
		}
	for (ll i = 1; i <= n; ++i)
		s[i] = a[i] + s[i - 1];{
		n2 = 1;
		if (a[0] != 0){
			for (ll i = 1; i <= n; ++i){
				if (a[i] != 0){
					cout << -1 << endl;
					return 0;
				}
			}
			b[0] = n2;
		}
		else{
			if (n == 0){
				cout << -1 << endl;
				return 0;
			}
			else
				b[0] = n2;
		}
	}
	for (unsigned long long i = 1; i <= n; i++){
		if (flag == 0){
			n2 = n2 * 2;
			if (a[i] > n2){
				cout << -1 << endl;
				return 0;
			}
			else{
				maxi = s[n] - s[i - 1];
				if (maxi <= n2){
					flag = 1;
					n2 = maxi;
					b[i] = n2;
					n2 = n2 - a[i];
				}
				else{
					b[i] = n2;
					n2 = n2 - a[i];
				}
			}
		}
		else{
			b[i] = n2;
			n2 = n2 - a[i];
		}
	}
	for (ll i = 0; i <= n; ++i)
		sum += b[i];
	cout << sum << endl;
	return 0;
}

