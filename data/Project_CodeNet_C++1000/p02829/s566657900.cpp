#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int A, B;
	cin >> A >> B;
	int ans;
	for (int i = 1; i <= 3; i++) {
		if (i != A && i != B) ans = i;
	}
	cout << ans << endl;
	return 0;
}
