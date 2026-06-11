#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	string t, op, p;
	int q, a, b;

	cin >> t;
	cin >> q;

	for (int i = 0; i < q; i++) {
		cin >> op;
		if (op == "print") {
			cin >> a >> b;
			cout << t.substr(a, b-a+1) << endl;
		}
		if (op == "reverse") {
			cin >> a >> b;
			reverse(t.begin()+a, t.begin()+b+1);
		}
		if (op == "replace") {
			cin >> a >> b >> p;
			t.replace(t.begin()+a, t.begin()+b+1, p);
		}
	}

	return 0;
}