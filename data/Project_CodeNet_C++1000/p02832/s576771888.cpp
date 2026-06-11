#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fix cout << fixed; cout << setprecision(0)





void solve() {

	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int cnt = 0;
	int k = 1;
	for(int i = 0; i < n; i++) {
		if(arr[i] != k) {
			cnt++;
		}
		else {
			k++;
		}
	}
	if(cnt == n) {
		cout << -1;
	}
	else {
		cout << cnt;
	}
	




	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	fix;
	solve();

	return 0;
}