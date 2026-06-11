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
	string ans = "Good";
	for (int i = 0; i < 3; i++) {
		int j = i + 1;
		if (S[i] == S[j]) ans = "Bad";
	}
	cout << ans << endl;
	return 0;
}