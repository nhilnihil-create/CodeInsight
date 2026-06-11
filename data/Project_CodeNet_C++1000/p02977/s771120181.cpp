#include<iostream>
using namespace std;
//long long int aa[100000];
int main() {
	//C
	int n;
	cin >> n;

	int i,j,k;
	i = n;
	while (1) {
		if (i % 2 == 1) {
			if (i == 1) {
				cout << "No";
				return 0;
			}
			else {
				break;
			}
		}
		else {
			i = i / 2;
		}
	}
	j = n;
	k = 1;
	while (j > 0) {
		if (j > 1) {
			j = j - (j % 2);
			j = j / 2;
			k = k * 2;
		}
		else {
			break;
		}
	}

	cout << "Yes\n";

	cout << 3 + n;
	cout << ' ';
	cout << 1 + n;
	cout << '\n';

	cout << 1 + n;
	cout << ' ';
	cout << 2 + n;
	cout << '\n';

	cout << 2 + n;
	cout << ' ';
	cout << 3;
	cout << '\n';

	cout << 3;
	cout << ' ';
	cout << 1;
	cout << '\n';

	cout << 1;
	cout << ' ';
	cout << 2;
	cout << '\n';

	if (n > 3) {
		cout << 1;
		cout << ' ';
		cout << 4;
		cout << '\n';
		cout << 1;
		cout << ' ';
		cout << 5 + n;
		cout << '\n';
		if (n % 2 == 1) {
			for (i = 4; i < n; i++) {
				cout << i;
				cout << ' ';
				cout << i + 1;
				cout << '\n';
			}
			for (i = 4; i < n; i = i + 2) {
				cout << i + n;
				cout << ' ';
				cout << i + 1 + n;
				cout << '\n';
				if (i + 3 <= n) {
					cout << i + n;
					cout << ' ';
					cout << i + 3 + n;
					cout << '\n';
				}
			}
		}
		else {
			for (i = 4; i < n - 1; i++) {
				cout << i;
				cout << ' ';
				cout << i + 1;
				cout << '\n';
			}
			for (i = 4; i < n - 1; i = i + 2) {
				cout << i + n;
				cout << ' ';
				cout << i + 1 + n;
				cout << '\n';
				if (i + 3 <= n - 1){
					cout << i + n;
					cout << ' ';
					cout << i + 3 + n;
					cout << '\n';
				}
			}
			if (n % 4 == 2) {
				cout << n;
				cout << ' ';
				cout << 2 * n - 1;
				cout << '\n';
				cout << 2;
				cout << ' ';
				cout << 2 * n;
				cout << '\n';

			}
			else {
				cout << n;
				cout << ' ';
				cout << k;
				cout << '\n';
				cout << 2 * n;
				cout << ' ';
				cout << n-k+1+n;
				cout << '\n';

			}

		}
	}



	return 0;
		//A
	/*int n;
	cin >> n;

	int i;

	for (i = 0; i < n; i++) {
		cin >> aa[i];
	}
	long long int  a, b, c;
	a = 0;
	b = 0;
	c = 0;
	int counta = 0;
	int countb = 0;
	int countc = 0;

		for (i = 0; i < n; i++) {
			if (counta == 0) {
				counta++;
				a = aa[i];
			}
			else {
				if (aa[i] == a) {
					counta++;
				}
				else {
					if (countb == 0) {
						countb++;
						b = aa[i];
					}
					else {
						if (aa[i] == b) {
							countb++;
						}
						else {
							if (countc == 0) {
								countc++;
								c = aa[i];
							}
							else {
								if (aa[i] == c) {
									countc++;
								}
								else {
									cout << "No";
									return 0;
								}
							}
						}
					}
				}
			}
		}
		if ((counta == countb) && (countb == countc)) {
			if (a == (b ^ c)) {
				cout << "Yes";
			}
			else {
				cout << "No";
			}
			return 0;
		}
		else if ((counta == n) && (a == 0)) {
			cout << "Yes";
		}
		else if ((counta == 2 * countb) && (b == 0) && (countc == 0)) {
			cout << "Yes";
		}
		else if ((2 * counta == countb) && (a == 0) && (countc == 0)) {
			cout << "Yes";
		}
		else {
			cout << "No";
			return 0;
		}
	*/
}