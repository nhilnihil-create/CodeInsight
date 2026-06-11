#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n,k;
	cin >> n >> k;
	long long arr[n],ans = 0;
	
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
		if(arr[i] >= k) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}