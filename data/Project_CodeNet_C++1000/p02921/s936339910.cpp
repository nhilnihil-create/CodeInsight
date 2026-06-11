#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
	string s, t;
	cin >> s >> t;
	int count = 0;
	rep(i, s.size()) {
		if(s[i] == t[i]) count++;
	}
	printf("%d\n", count);
	return 0;
}