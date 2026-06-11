#include <iostream>

using namespace std;
using ll = long long;

int main() {
	string S;
	cin >> S;

	int cnt = 0;
	for (int i = 0; i < S.size() / 2; ++i) {
		int end = S.size() - 1;

		if (S[i] != S[end - i]) {
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}
