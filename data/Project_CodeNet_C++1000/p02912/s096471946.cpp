#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll INF = 1LL<<60;
//int INF = numeric_limits<int>::max();

int main(int, char**) {
	int n, m; cin >> n >> m;
	priority_queue<int> A;
	for (int i=0; i<n; i++) {
		int a; cin >> a;
		A.push(a);
	}
	for (int i=0; i<m; i++) {
		int h = A.top();
		A.pop();
		A.push(h/2);
	}
	ll ret = 0;
	for (int i=0; i<n; i++) {
		ret += A.top();
		A.pop();
	}
	cout << ret << endl;
	return 0;
}