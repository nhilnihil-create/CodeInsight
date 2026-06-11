#include <bits/stdc++.h>
using namespace std;
#define debug(x) cerr << # x << "; "<< x << endl


int main() {
	int A, B, C, D;
	cin >> A >> B >> C >> D;
	for (int i = 0; i < 200; i++) {
			C -= B;
			if (C <= 0) {
				cout << "Yes" << endl;
				break;
			}
			else if (A > 0) {
				A -= D;
				if (A <= 0) {
				cout << "No" << endl;
				break;
			}
		}
	}
}
