#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <set>
#include <map>
using namespace std;



void solve()
{
	string s;
	cin >> s;
	int n = (int)s.length();

	if (n & 1)
	{
		cout << "No";
		return;
	}

	for (int i = 0; i < n; i+=2)
	{
		if (!(s[i] == 'h' && s[i + 1] == 'i'))
		{
			cout << "No";
			return;
		}
	}

	cout << "Yes";
}

int main()
{
	//freopen("file.in", "w", stdin); freopen("file.out", "w", stdout);
	solve();
}