#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector< int > a(n);
	for (auto& e:a)cin >> e;
	ll curr = 1000;
	for (int i=0;i+1<n;i++) {
		ll s = 0;
		if (a[i] < a[i+1]) s=curr/a[i];
		curr += ((ll)a[i+1]-a[i])*s;
	}
	cout << curr << '\n';
	
	return 0;
}
