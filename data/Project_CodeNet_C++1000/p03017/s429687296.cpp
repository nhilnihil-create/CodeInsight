#include <iostream>
#include <vector>

using namespace std;
int main() {
	int N, A, B, C, D;
	cin >> N >> A >> B >> C >> D;
	string S;
	cin >> S;
	for (int i = A; i < C; i++) {
		if (S[i - 1] == '#' && S[i] == '#') {
			cout << "No" << endl;
			return 0;
		}
	}
	for (int i = B; i < D; i++) {
		if (S[i - 1] == '#' && S[i] == '#') {
			cout << "No" << endl;
			return 0;
		}
	}
	if (C < D) {
		cout << "Yes" << endl;
	}
	else {
		for (int i = B - 1; i < D; i++) {
			if (S[i - 1] == '.' && S[i] == '.' && S[i + 1] == '.') {
				cout << "Yes" << endl;
				return 0;
			}
		}
		cout << "No" << endl;
	}
}