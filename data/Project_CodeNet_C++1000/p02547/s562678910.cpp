#include <bits/stdc++.h>
const long long MOD = 1e9+7;
using namespace std;
#define ll long long
#define ar array

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;
	int ans = 0;

	for (int i = 0; i < N; i++) {
		int D1,D2;
		cin >> D1 >> D2;
		if (D1==D2) ans++;
		else ans=0;
		if (ans==3) {
			cout << "Yes" << endl;
          	return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}
