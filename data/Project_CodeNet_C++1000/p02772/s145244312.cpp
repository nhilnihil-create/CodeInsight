#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int N;
	cin >> N;
	string ans = "APPROVED";
	for (int i = 0; i < N; i++) {
		int A;
		cin >> A;
		if (A % 2 == 0) {
			if (A % 3 != 0 && A % 5 != 0) ans = "DENIED";
		}
	}
	cout << ans << endl;
	return 0;
}