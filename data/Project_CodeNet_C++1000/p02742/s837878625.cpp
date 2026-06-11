#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 5LL << 60;
const ll mod = 1e9 + 7;

int main() {
	ll H, W;
	cin >> H >> W;
	if(H == 1 || W == 1)
		cout << 1;
	else
		cout << (H * W + 1) / 2;
	return 0;
}
