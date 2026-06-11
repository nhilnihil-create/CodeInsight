#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n;
	string s; cin >> n >> s;
	for (int i = 0; i < s.size(); i++) {
		int tmp = (s[i] - 'A') + n;
		if (26 <= tmp) tmp -= 26;
		char c = tmp + 'A';
		s[i] = c;
	}
    cout << s << endl;
}