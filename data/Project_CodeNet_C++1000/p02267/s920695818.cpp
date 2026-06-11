#include <cstdio>
#include <iostream>

using namespace std;

int main() {

	int n, S[10000] = { 0 }, q, T[500] = { 0 };
	int cnt = 0;

	cin >> n;

	for (int i = 0;i < n;i++) {
		cin >> S[i];
	}

	cin >> q;

	for (int i = 0;i < q;i++) {
		cin >> T[i];
	}

	for (int i = 0;i < q;i++) {
		for (int j = 0;j < n;j++) {
			if (S[j] == T[i]) {
				cnt++;
				break;
			}
		}
	}

	cout << cnt << endl;

	return 0;
}