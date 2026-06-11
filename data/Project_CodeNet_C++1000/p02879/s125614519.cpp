#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll INF = 1LL<<60;
//int INF = numeric_limits<int>::max();

int main(int, char**) {
	int a, b; cin >> a >> b;
	int ret;
	if (a>9 || b>9) ret = -1;
	else ret = a * b;
	cout << ret << endl;
	return 0;
}