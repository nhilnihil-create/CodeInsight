#include <bits/stdc++.h>
#define FIO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl "\n"

using namespace std;

const int N = int(10e5 + 5);

int main() {
	FIO
	int A, B, C; cin >> A >> B >> C;
	int k; cin >> k;
	int cnt = 0;
	while (A >= B) {
		cnt++;
		B *= 2;
	}
	while (B >= C) {
		cnt++;
		C *= 2;
	}
	(cnt <= k) ? cout << "Yes" : cout << "No";
	return 0;
}