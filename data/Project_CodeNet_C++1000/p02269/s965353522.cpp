#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	set<string> st;
	set<string>::iterator it;
	string s1, s2;
	int n;
	cin >> n;

	while (n--) {
		cin >> s1 >> s2;
		if (s1 == "insert") {
			st.insert(s2);
		}
		else {
			it = st.find(s2);
			if (it != st.end()) {
				cout << "yes" << endl;
			}
			else {
				cout << "no" << endl;
			}
		}
	}

	return 0;
}