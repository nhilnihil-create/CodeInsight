#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 5LL << 60;
const ll mod = 1e9 + 7;

int main() {
	ll A, B, N;
	cin >> A >> B >> N;

	ll tmp = min(N, B - 1);
	cout << (A * tmp) / B - A * (tmp / B) << "\n";
}