#include <iostream>

using namespace std;

int main()
{
	int m, f, r, sum;
	while (true) {
		cin >> m >> f >> r;
		if (m == -1 && f == -1 && r == -1) break;
		if(m == -1 || f == -1) cout << "F" << endl;
		else {
			sum = m + f;
			if      (sum >= 80) cout << "A" << endl;
			else if (sum >= 65) cout << "B" << endl;
			else if (sum >= 50) cout << "C" << endl;
			else if (sum >= 30) cout << (r >= 50 ? "C" : "D") << endl;
			else cout << "F" << endl;
			
		}
	}
	return 0;
}