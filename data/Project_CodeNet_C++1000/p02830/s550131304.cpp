#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll INF = 1LL<<60;
//int INF = numeric_limits<int>::max();

int main(int, char**) {
	int n; cin >> n;
	string s, t;
	cin >> s >> t;
	string ret = "";
	for (int i=0; i<n; i++) {
		ret = ret + s[i] + t[i];
	}
	cout << ret << endl;
	return 0;
}