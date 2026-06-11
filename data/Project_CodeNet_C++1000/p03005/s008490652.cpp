#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	// int tmp = N - K;

	int ans = 0;
	if (K > 1){
		ans = N-K;
	}

	cout << ans << "\n";

	return 0;
}
