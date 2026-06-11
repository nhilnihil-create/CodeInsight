#include <bits/stdc++.h>
using namespace std;

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int A, V, B, W, T; cin >> A >> V >> B >> W >> T;
	if (A <= B) {
		long long a = (long long)A + (long long)V * T;
		long long b = (long long)B + (long long)W * T;
		cout << ((a >= b) ? "YES" : "NO") << "\n";
	} else {
		long long a = (long long)A - (long long)V * T;
		long long b = (long long)B - (long long)W * T;
		cout << ((a <= b) ? "YES" : "NO") << "\n";
	}
	
	return 0;
}
