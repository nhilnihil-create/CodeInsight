#include <bits/stdc++.h>

using namespace std;

bool judge(string S) {
	string tmp = S;
	reverse(tmp.begin(), tmp.end());

	if (S == tmp)return true;
	else return false;
}

int main(void) {
	string S, substr1, substr2;

	cin >> S;

	substr1 = S.substr(0, (S.size() - 1) / 2);
	substr2 = S.substr((S.size() + 3) / 2 -1, (S.size() - 1) / 2);

	if (judge(S) && judge(substr1) && judge(substr2)) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}
