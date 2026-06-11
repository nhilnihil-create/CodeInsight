#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int N, X, T;
	cin >> N >> X >> T;
	int res = (N + X - 1) / X * T;
	cout << res << '\n';

	return 0;
}

