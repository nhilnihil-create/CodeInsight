#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 5LL << 60;
const ll mod = 1e9 + 7;

int main() {
	ll M;
	cin >> M;
	ll D = 0, C = 0;
	for(int i = 0; i < M; i++) {
		ll d, c;
		cin >> d >> c;
		D += d * c;
		C += c;
	}
	cout << C + (D - 1) / 9 - 1;
	return 0;
}