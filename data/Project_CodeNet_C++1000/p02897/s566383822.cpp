#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll INF = 1LL<<60;
//int INF = numeric_limits<int>::max();

int main(int, char**) {
	int n; cin >> n;
	double d = 1 - (n / 2) / (double)n;
	cout << setprecision(10) <<  d << endl;
	return 0;
}