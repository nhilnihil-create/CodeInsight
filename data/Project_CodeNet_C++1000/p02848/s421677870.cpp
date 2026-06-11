#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		int c = s[i]-65;
		c += n;
		if (c >= 26)
			c -= 26;
		printf("%c", 65+c);
	}
	cout << endl;
	return 0;
}