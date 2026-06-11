#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	
	int n; cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll A = 0;
	for (int i = 0; i < n; i++) {
		A = A ^ a[i];
	}
	for (int i = 0; i < n; i++) {
		cout << (A ^ a[i]) << " ";
	}
	cout << endl;
    return 0;
}