#include <iostream>
using namespace std;
main () {
	int m, f, r;
	while (cin >> m >> f >> r, m!=-1||f!=-1||r!=-1) {
		if ((m == -1 || f == -1) || m + f < 30) cout << "F" << endl;
		else if (m + f >= 80) cout << "A" << endl;
		else if (m + f >= 65) cout << "B" << endl;
		else if (m + f >= 50 || r >= 50) cout << "C" << endl;
		else cout << "D" << endl;
	}
}