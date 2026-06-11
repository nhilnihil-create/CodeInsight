#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll INF = 1LL<<60;
//int INF = numeric_limits<int>::max();

int main(int, char**) {
	string s, t; cin >> s >> t;
	int ret  = 0;
	for (int i=0; i<3; i++) if (s[i]==t[i]) ret++;
	cout << ret << endl;
	return 0;
}