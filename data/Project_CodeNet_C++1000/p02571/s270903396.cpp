#include <bits/stdc++.h>
using namespace std;

int main() {
	string S, T;
	cin >> S >> T;
	int a = 0;

	for (int i = 0; i < S.size() - T.size() + 1; i++) {
		int count = 0;
		for (int j = 0; j < T.size(); j++) {

			if (T.at(j) == S.at(j + i)) {
				count++;
			}
			if (j == T.size() - 1) {
				if (a <= count) {
					a = count;
				}
			}
		}
	}cout << T.size() - a;
	
}