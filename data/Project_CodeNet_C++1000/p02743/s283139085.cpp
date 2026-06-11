#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef pair<int, int> P;
typedef long long ll;

bool check(ll a, ll b, ll c) {
	//?sqrt(a)+sqrt(b)<sqrt(c)
	if (c - a - b >= 0 && 4 * a * b < (c - a - b) * (c - a - b)) {
		return true;
	}
	return false;
}

int main() {
	ll a, b, c;
	cin >> a >> b >> c;
	if (check(a, b, c)) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

	return 0;
}