#include <iostream>

using namespace std;
using ll = long long;

int main() {
	int N;
	string S, T;
	cin >> N;
	cin >> S >> T;

	string ans = "";
	for (int i = 0; i < N; ++i) {
		ans += S[i];
		ans += T[i];
	}
	cout << ans << endl;

	return 0;
}
