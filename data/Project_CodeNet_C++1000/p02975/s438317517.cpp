#include<iostream>
using namespace std;
long long int aa[100000];
int main() {
	int n;
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
	
}