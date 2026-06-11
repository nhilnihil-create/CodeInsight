#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;

void swap(int a,int b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int main(void) {
	ll k,n;
	cin >> k >> n;
	vector<ll>a(n + 5);

	for (int i = 0; i < n;i++) {
		cin >> a[i];
	}

	ll b = 0;
	ll ans = 0;

	for (int i = 0; i < n-1; i++) {
		b = max(b,a[i+1]-a[i]);
		ans += a[i + 1] - a[i];
	}

	b= max(b, k-a[n - 1]+a[0]);
	ans += k - a[n - 1] + a[0];

	ans -= b;

	cout << ans << endl;
	
	return 0;
}