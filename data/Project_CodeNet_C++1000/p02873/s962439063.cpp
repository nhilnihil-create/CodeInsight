#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;

int main() {
	string s;
	cin >> s;
	int n = s.size();
	long long ans = 0;
	int arr[n + 1] = { 0 };
	for (int i = 0; i < n ; i++) {
		if (s[i] == '<') {
			arr[i + 1] = max(arr[i] + 1, arr[i + 1]);
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == '>') {
			arr[i] = max(arr[i], arr[i + 1] + 1);
		}
	}

	for (int i = 0 ; i <= n ; i++) ans += arr[i];
	printf("%lld\n", ans);
}

