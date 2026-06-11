#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+5;
int k;
string s;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);

	cin >> k >> s;
	if(s.size() <= k)
		cout << s << endl;
	else
	{
		for(int i = 0; i < s.size(); i++)
			if(i == k - 1)
			{
				cout << s[i];
				break;
			}
			else
				cout << s[i];
		cout << "...";
	}
	return 0;
}
