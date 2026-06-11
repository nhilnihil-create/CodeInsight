#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	cin>>s;
	pair<char, int> a;
	pair<char, int> b;
	a.second=1;
	b.second=0;
	a.first=s[0];
	bool primer_diferente=false;
	for (int i=1; i<s.size(); i++)
	{
		if (s[i]==a.first)
			a.second++;
		else
		{
			if (!primer_diferente)
			{
				b.first=s[i];
				b.second++;
				primer_diferente=true;
			}
			else
			{
				if (s[i]==b.first)
				{
					b.second++;
				}
				else
				{
					cout<<"No\n";
					return 0;
				}
			}
		}
	}
	if (a.second==2&&b.second==2) cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}