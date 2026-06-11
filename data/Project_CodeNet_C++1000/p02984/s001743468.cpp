#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll INF = 1LL<<60;
//int INF = numeric_limits<int>::max();

int main(int, char**) {
	int n; cin >> n;
	vector<ll> A;
	ll last;
	A.push_back(0);
	for (int i=1; i<n; i++) {
		ll a; cin >> a;
		A.push_back(2*a - A[i - 1]);
	}
	ll diff; cin >> diff;
	diff -= A[n - 1]/2;
	vector<ll> f{1, -1};
	for (int i=0; i<n; i++) {
		cout << A[i] + (diff * f[i%2]) << " ";
	}
	cout << endl;
	return 0;
}