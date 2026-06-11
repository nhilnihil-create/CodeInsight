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
	ll n;
	cin >> n;

	vector<ll>a(n + 5);
	vector<ll>count(n + 5);
	vector<ll>ans(n + 5);
	ll total = 0;

	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (ll i = 1; i <= n; i++) {
		count[i] = 0;
		ans[i] = 0;
	}

	for (ll i = 0; i < n; i++) {
		count[a[i]]++;
	}

	for (ll i = 1; i <= n; i++) {
		total+=count[i]*(count[i]-1)/2;
	}

	for (ll i = 1; i <= n; i++) {
		ans[i]= total- (count[i]-1);
	}

	for (ll i = 0; i < n; i++) {
		cout << ans[a[i]] << endl;
	}

	return 0;
}