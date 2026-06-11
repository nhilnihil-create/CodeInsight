#include<iostream>
#include <string>

using namespace std;

int main(void) {

	int N;
	int t[55];
	string S[55];

	cin >> N;
	for (int i = 1; i <= N; i++) { cin >> S[i] >> t[i]; }

	string X;
	cin >> X;

	int ans = 0;
	for (int i = 1; i <= N; i++) { ans += t[i]; }

	for (int i = 1; i <= N; i++) {
		ans -= t[i];
		if (X == S[i]) { break; }
	}
	cout << ans << endl;
	return 0;
}