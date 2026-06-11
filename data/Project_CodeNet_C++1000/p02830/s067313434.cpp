#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	for (int i = 0; i < n; i++) {
		printf("%c%c", s[i], t[i]);
	}
	cout << endl;
	return 0;
}