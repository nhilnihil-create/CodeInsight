#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll INF = 1LL<<60;
//int INF = numeric_limits<int>::max();

int main(int, char**) {
	int l, r, d;
	cin >> l >> r >> d;
	cout << r/d - (l - 1)/d << endl;
	return 0;
}