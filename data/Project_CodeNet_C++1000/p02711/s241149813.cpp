#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	string N;
	cin >> N;
	bool ok = false;
	for (int i = 0; i < 3; i++) {
		if (N[i] - '0' == 7) ok = true;
	}
	if (ok) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}