#include <iostream>
using namespace std;
main () {
	int n, a=0, b=0;
	cin >> n;
	for (int i=0; i<n; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		if (s1 > s2) a += 3;
		else if (s1 < s2) b += 3;
		else {
			a++;
			b++;
		}
	}
	cout << a << " " << b << endl;
}