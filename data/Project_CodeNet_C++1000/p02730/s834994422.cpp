#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool kaibun(string s) {
	string t;
	int n = s.size();
	for (int i = n - 1; i >= 0; i--) {
		t.push_back(s[i]);
	}
	if (s == t) return true;
	else return false;
}

int main() {
	string S;
	cin >> S;
	int N = S.size();
	string a = S.substr(0, (N - 1) / 2);
	string b = S.substr((N + 3) / 2 - 1);
	if (kaibun(S) && kaibun(a) && kaibun(b)) cout << "Yes" << endl;
	else cout << "No" << endl;
}