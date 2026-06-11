#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string s1, s2;	
	cin >> s1 >> s2;
	int a, b;
	cin >> a >> b;
	string s3;
	cin >> s3;
	if (s3 == s1)
	{
		a--;
	}
	else if (s3 == s2)
	{
		b--;
	}
	cout << a << " " << b << endl;
	return 0;
}