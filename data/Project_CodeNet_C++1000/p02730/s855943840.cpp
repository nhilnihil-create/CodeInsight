#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

bool isKaibun(string& S) {
	bool ans = true;
	for (int i = 0; i < S.size() / 2; ++i) {
		if (S[i] != S[S.size() - 1 - i]) {
			ans = false;
			break;
		}
	}
	return ans;
}

int main() {
	string S;
	cin >> S;

	bool ans = isKaibun(S);
	if (!ans) {
		cout << "No" << endl;
		return 0;
	}

	string tmp = S.substr(0, ((S.size() - 1) / 2));
	ans = isKaibun(tmp);
	if (!ans) {
		cout << "No" << endl;
		return 0;
	}

	tmp = S.substr(((S.size()+3) / 2) -1);
	ans = isKaibun(tmp);
	if (!ans) {
		cout << "No" << endl;
		return 0;
	}

	cout << "Yes" << endl;
	return 0;
}
