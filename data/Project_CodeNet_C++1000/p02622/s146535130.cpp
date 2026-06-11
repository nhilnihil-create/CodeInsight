#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	string s,t;
	int res = 0;
	int n;

	cin >> s;
	cin >> t;
	n = s.length();

	for(int i=0;i<n;i++)
	{
		if(s[i]!=t[i])
		{
			res++;
		}
	}

	cout << res << '\n';
	
	return 0;
}