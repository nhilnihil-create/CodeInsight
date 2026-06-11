#include <iostream>
using namespace std;
main () {
	string str;
	while (cin >> str, str != "-") {
		int m, h;
		cin >> m;
		for (int i=0; i<m; i++) {
			cin >> h;
			str = str.substr(h) + str.substr(0, h);
		}
		cout << str << endl;
	}
}