#include <bits/stdc++.h>
using namespace std;
int main() {
	int k; cin >> k, --k;
	string s = "ACL";
	while(k--)
		s += "ACL";
	cout << s;
	return 0;
}
