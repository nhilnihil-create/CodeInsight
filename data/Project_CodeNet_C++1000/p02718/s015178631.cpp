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
	ll n,m;
	cin >> n >> m;

	vector<ll>a(n);
	float total=0;

	for (int i = 0; i < n;i++) {
		cin >> a[i];
		total += a[i];
	}

	sort(a.begin(),a.end());

	for (int i = 1; i <= m; i++) {
		if (a[n - i] < total/(4*m) ) {
			cout << "No" << endl;
			return 0;
		}
	}

	cout << "Yes" << endl;
	return 0;
}