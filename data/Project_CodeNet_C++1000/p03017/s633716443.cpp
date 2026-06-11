	#include <iostream>
	#include <string>
	using namespace std;

	int main() {
		long long N, A, B, C, D; cin >> N >> A >> B >> C >> D;
		string S; cin >> S;
		if (C < D) {
			for (long long i = A; i < D; i++) {
				if (S.at(i) == '#' && S.at(i - 1) == '#') {
					cout << "No" << endl;
					return 0;
				}
			}
			cout << "Yes" << endl;
		}
		else {
			for (long long i = A; i < C; i++) {
				if (S.at(i) == '#' && S.at(i - 1) == '#') {
					cout << "No" << endl;
					return 0;
				}
			}
			for (long long i = B; i < D + 1; i++) {
				if (S.at(i) == '.' && S.at(i - 1) == '.' && S.at(i - 2) == '.') {
					cout << "Yes" << endl;
					return 0;
				}
			}
			cout << "No" << endl;
		}
	}
