
#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
	string s;
	cin >> s;
	rep(i, s.size() - 1) {
		if (s[i] == s[i + 1]) {
			printf("Bad\n");
			return 0;
		}
	}
	printf("Good\n");
	return 0;
}