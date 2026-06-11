#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
	string s;
	cin >> s;
	int ans = 0;
	rep(i, s.size()) {
		if(s[i] != s[s.size() - 1 - i]) ans++;
	}
	printf("%d\n", ans / 2);
}