#include <bits/stdc++.h>
using namespace std;

string s;

int main()
{
	cin >> s;
	string S, T;
	S = T = "";
	int ans = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		S += s[i];
		if (S != T)
		{
			++ans;
			T = S;
			S = "";
		}
	}
	cout << ans << endl;
	return 0;
}