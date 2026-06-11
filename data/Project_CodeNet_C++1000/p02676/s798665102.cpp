#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	if ((int)s.size() > n) {
		cout << s.substr(0,n) + "...";
	} else {
		cout << s;
	}
	return 0;
}
