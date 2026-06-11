#include <bits/stdc++.h>

using namespace std;

int main()
{

	string S, T;

	cin >> S >> T;

	string ans = "Yes";

	if (S.length() != T.length() - 1)
		ans = "No";

	else
	{
		for (int i = 0; i < S.length(); i++)
		{
			if (S[i] != T[i])
			{
				ans = "No";
				break;
			}
		}
	}

	cout << ans << endl;

}
