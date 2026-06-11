#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;
using ll = long long;

int main() {
	string S;
	cin >> S;

	string ans = "Yes";
	for (int i = 1; i <= S.size(); ++i) {
		if (i % 2 == 0) {
			if (S[i-1] == 'R') {
				ans = "No";
				break;
			}
		}
		else {
			if (S[i-1] == 'L') {
				ans = "No";
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
