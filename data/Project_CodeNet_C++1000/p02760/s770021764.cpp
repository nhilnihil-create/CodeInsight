#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

void b_bingo(void) {
	int a[3][3];
	int n;
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 3; i++) {
			cin >> a[j][i];
		}
	}
	cin >> n;
	vector<int>b(n);
	for (int i = 0; i < n; i++)cin >> b[i];

	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 3; i++) {
			for (int k = 0; k < n; k++) {
				if (b[k] == a[j][i]) {
					a[j][i] = 0;
				}
			}
		}
	}

	// yoko
	int cnt = 0;
	for (int j = 0; j < 3; j++) {
		cnt = 0;
		for (int i = 0; i < 3; i++) {
			if (a[j][i] == 0) cnt++;
		}
		if (cnt == 3) {
			cout << "Yes" << endl;
			return;
		}
	}
	// tate
	for (int i = 0; i < 3; i++) {
		cnt = 0;
		for (int j = 0; j < 3; j++) {
			if (a[j][i] == 0) cnt++;
		}
		if (cnt == 3) {
			cout << "Yes" << endl;
			return;
		}
	}
	// naname
	if ((a[0][0] == 0) && (a[1][1] == 0) && (a[2][2] == 0)) {
		cout << "Yes" << endl;
		return;
	}
	else if ((a[0][2] == 0) && (a[1][1] == 0) && (a[2][0] == 0)) {
		cout << "Yes" << endl;
		return;
	}

	cout << "No" << endl;

}

int main()
{
    b_bingo();

    return 0;
}