#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	int A, B;
	cin >> A >> B;

	if ( (A < 10) && (B < 10)){
		cout << A*B << "\n";
	} else {
		cout << -1 << "\n";
	}
	return 0;
}
