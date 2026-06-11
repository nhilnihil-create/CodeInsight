#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll INF = 1LL<<60;
//int INF = numeric_limits<int>::max();

int main(int, char**) {
	string s; cin >> s;
	string ret = "Yes";
	for (int i=0; i<s.size(); i++) {
		if (i%2==0 && s[i]=='L') {
			ret = "No";
			break;
		}
		if (i%2==1 && s[i]=='R') {
			ret = "No";
			break;
		}
	}
	cout << ret << endl;
	return 0;
}