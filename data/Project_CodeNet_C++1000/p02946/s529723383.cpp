#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll INF = 1LL<<60;
//int INF = numeric_limits<int>::max();

int main(int, char**) {
	int k, x; cin >> k >> x;
	int start = x - k + 1;
	int goal = x + k - 1;
	for (int i=start; i<=goal; i++) cout << i << " ";
	cout << endl;
	return 0;
}
