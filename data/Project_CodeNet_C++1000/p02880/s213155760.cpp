#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			if (N == i * j) {
				cout << "Yes" << endl;
				exit(0);
			}
			else if (N != i * j && i == 9 && j == 9) {
				cout << "No" << endl;
			}
		}
	}
}