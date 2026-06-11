#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
	int n;
	scanf("%d", &n);
	string s, t;
	cin >> s >> t;
	rep(i, n) {
		cout << s[i] << t[i];
	}
	cout << endl;
	return 0;
}