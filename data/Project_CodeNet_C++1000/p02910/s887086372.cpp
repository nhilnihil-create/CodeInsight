#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	string S;
	cin >> S;
	string ans = "Yes";
	for (int i = 0; i < S.size(); i++) {
		if ((i + 1) % 2 == 1 && S[i] == 'L') ans = "No";
		else if ((i + 1) % 2 == 0 && S[i] == 'R') ans = "No";
	}
	cout << ans << endl;
	return 0;
}