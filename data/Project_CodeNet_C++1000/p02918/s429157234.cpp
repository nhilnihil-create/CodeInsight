#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll INF = 1LL<<60;
//int INF = numeric_limits<int>::max();

int main(int, char**) {
	int n, k; cin >> n >> k;
	string s; cin >> s;
	int ret=0;
	for (int i=0; i<n-1; i++) {
		if (s[i]==s[i+1]) ret++;
	}
	ret += 2*k;
	cout << min(n-1, ret) << endl;
	return 0;
}