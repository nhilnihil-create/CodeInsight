#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i < (int)(n); i++)
using ll = long long;
using namespace std;

int main() {
	string s;
	cin >> s;
	bool ans = true;
	char tmp;
	rep(i, 4) {
		tmp = s[i];
		if (s[i + 1] == tmp)ans = false;
	}

	if (ans) {
		cout << "Good" << endl;
	}
	else {
		cout << "Bad" << endl;
	}
	return 0;
}
