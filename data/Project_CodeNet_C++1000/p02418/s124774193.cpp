#include <iostream>
using namespace std;
main () {
	string s, p;
	cin >> s >> p;
	s = s + s;
	cout << (s.find(p) != string::npos ? "Yes" : "No") << endl;
}