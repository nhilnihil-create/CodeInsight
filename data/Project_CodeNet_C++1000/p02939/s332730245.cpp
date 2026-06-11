#include <iostream>
#include <string>
using namespace std;

int main() {
	string S;
	cin >> S;
	int cnt = 1;
	string pre = S.substr(0, 1);
	for (int i = 1; i < (int)S.size(); i++) {
		string t = S.substr(i, 1);
		if (pre == t) {
			if (i == (int)S.size() - 1) break;
			t += S.at(i + 1);
			i++;
		}
		pre = t;
		cnt++;
	}
	cout << cnt << endl;
}