#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
	int n;
	scanf("%d", &n);
	string s;
	cin >> s;
	int count = 0;
	rep(i, n - 2) {
		if(s[i] == 'A'&& s[i + 1] == 'B'&& s[i + 2] == 'C') count++;
	}
	printf("%d\n", count);
	return 0;
}