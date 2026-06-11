#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	ll N, A, B;
	cin >> N >> A >> B;


	ll ans = 0;
	if ( (B - A) % 2 == 0 ){
		ans = (B - A) / 2;
	} else {
		if (A - 1 < N - B){
			ans = A + (B - A - 1) / 2;
		} else {
			ans = N - B + 1 + (B - A - 1) / 2;
		}
	}

	cout << ans << "\n";

	return 0;
}
