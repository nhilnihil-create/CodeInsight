#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	int ans = 0;
	for (int ii = 0; ii < N; ++ii){
		int H;
		cin >> H;
		if (H >= K){
			ans++;
		}
	}


		cout << ans << "\n";

	return 0;
}
