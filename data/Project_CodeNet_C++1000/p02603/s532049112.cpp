#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;
int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	rep(i,n) cin >> v[i];
	ll y = 1000;
	rep(i,n) {
		int s = v[i];
		ll t = y / v[i];
		while (i + 1 < n && v[i] <= v[i+1]) i++;
		y = (y - t * s) + (t * v[i]);
	}
	cout << y << endl;
}