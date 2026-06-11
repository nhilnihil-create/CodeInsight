#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int inf = 1e9 + 7;
const ll longinf = 5LL << 60;
const ll mod = 1e9 + 7;

int main() {
	int N, K;
	cin >> N >> K;
	if(K == 1)
		cout << 0;
	else
		cout << N - K;

	return 0;
}
