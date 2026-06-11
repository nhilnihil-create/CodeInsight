#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	if (n & 1)
		return cout << "No" << '\n', 0;
	for (int i = 0; i < n / 2; ++i)
	{
		if (s[i] != s[i + n / 2])
			return cout << "No" << '\n', 0;
	}
	cout << "Yes" << '\n';
	return 0;
}