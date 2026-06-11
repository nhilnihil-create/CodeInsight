#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	string s;
	string t;

	cin >> n;
	cin >> s;

	if(n%2==1)
	{
		cout << "No" << '\n';
	}
	else
	{
		t = s.substr(0,n/2);
		t = t + t;
		if(s==t)
		{
			cout << "Yes" << '\n';
		}
		else
		{
			cout << "No" << '\n';
		}
	}
	return 0;
}
