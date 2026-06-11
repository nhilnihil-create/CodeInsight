#include <iostream>
#include <algorithm>
using namespace std;
main () {
	string w, t;
	int a = 0;
	cin >> w;
	transform(w.begin(), w.end(), w.begin(), ::tolower);
	while (cin >> t, t != "END_OF_TEXT") {
		transform(t.begin(), t.end(), t.begin(), ::tolower);
		if (w == t) a++;
	}
	cout << a << endl;
}