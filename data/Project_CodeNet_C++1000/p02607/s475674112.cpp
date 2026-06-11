#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll INF = 1LL<<60;
//int INF = numeric_limits<int>::max();

int main(int, char**) {
	int n; cin >> n;
	int ret = 0;
	for (int i=0; i<n; i++) {
		int a; cin >> a;
		if (i%2==0 && a%2==1) ret++;
	}
	cout << ret << endl;
	return 0;
}