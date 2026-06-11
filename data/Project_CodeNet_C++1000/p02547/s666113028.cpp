#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N; /*実行回数*/

	int D, Dn;

	int count = 0;
	int countt = 0;

	while (true) {
		if (countt == N) {
			break;
		}

		cin >> D >> Dn;

		if (D == Dn) {
			count++;
			if (3 <= count) {
				cout << "Yes";
				return 0;
			}
		}
		else if (D != Dn) {
			if (3 <= count) {
				cout << "Yes";
				return 0;
			}
			else {
				count = 0;
			}
		}

		countt++;
	}
		cout << "No";
	
}
