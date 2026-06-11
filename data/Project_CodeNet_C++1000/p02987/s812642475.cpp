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
	int count = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = i + 1; j < 4; j++) {
			if (S[i] == S[j]) count++;
		}
	}
	if (count == 2) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}