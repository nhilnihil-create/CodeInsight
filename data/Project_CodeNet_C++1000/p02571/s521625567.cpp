#include"bits/stdc++.h"
using namespace std;
typedef long long ll;

int main() {
	string  s,t;
	cin >> s >> t;
	int count = t.size();

	for (int i = 0; i <= s.size() - t.size();i++) {
		int ch = 0;
		for (int j = 0; j < t.size();j++) {
			if (s[j+i]!=t[j]) {
				ch++;
			}
		}
		count = min(count, ch);
	}

	cout << count << endl;

	return 0;
}
