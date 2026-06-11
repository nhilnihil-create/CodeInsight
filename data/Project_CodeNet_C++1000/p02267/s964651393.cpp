#include <iostream>
using namespace std;

int main () {
	int sn, tn, t, c = 0;
	cin >> sn;
	int *s = new int[sn];
	for (int i = 0; i < sn; i++)
		cin >> s[i];
	cin >> tn;
	for (int i = 0; i < tn; i++) {
		cin >> t;
		for (int j = 0; j < sn; j++) {
			if (s[j] == t) {
				c++;
				break;
			}
		}
	}
	cout << c << endl;
	return 0;
}