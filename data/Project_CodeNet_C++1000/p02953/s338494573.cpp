#include <cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
ll h[100005];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	int pre = -999;
	for (int i = 0; i < n; i++) {
		if (pre <= h[i] - 1) {
			pre = h[i] - 1;
		}
		else if (pre <= h[i]) {
			pre = h[i];
		}
		else {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}