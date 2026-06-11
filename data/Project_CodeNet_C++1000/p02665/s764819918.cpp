#include <bits/stdc++.h>
#include <algorithm>  
#include <unordered_set>
#define ll long long

using namespace std;


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;

	cin >> N;

	vector<ll> d(N + 1);
	ll m = 1;

	ll numberOfLeafNodes = 0;

	for (int i = 0; i <= N; i++) {
		cin >> d[i];
		numberOfLeafNodes += d[i];
	}

	if (N > 0 && d[0] > 0 || N == 0 && d[0] > 1) {
		cout << "-1" << endl;
	}
	else{

		ll ans = 1;

		for (int i = 1; i <= N; i++) {
			m = min(2 * m, numberOfLeafNodes);
			ans += m;

			if (d[i] > m) {
				cout << "-1" << endl;
				return 0;
			}

			m -= d[i];
			numberOfLeafNodes -= d[i];
		}

		cout << ans << endl;
	}




	
	
	return 0;
}