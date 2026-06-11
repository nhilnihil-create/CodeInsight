#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int N;
	string S;
	cin >> N >> S;

	int ans = 0;
	char ch = 0;
	for (int i = 0; i < N; ++i) {
		if (S[i] != ch) {
			ch = S[i];
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
