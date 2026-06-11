#include <bits/stdc++.h>

using namespace std;

#define ll long long




void solve() {

	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		if(arr[i] != i + 1) {
			cnt++;
		}
		if(cnt > 2) {
			break;
		}
	}
	if(cnt <= 2) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}

	




	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	solve();

	return 0;
}