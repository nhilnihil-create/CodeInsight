#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll INF = 1LL<<60;
//int INF = numeric_limits<int>::max();

int main(int, char**) {
	string s; cin >> s;
	string ret;
	if (s[0]==s[1] || s[1]==s[2] || s[2]==s[3]) ret = "Bad";
	else ret = "Good";
	cout << ret << endl;
	return 0;
}