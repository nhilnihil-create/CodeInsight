#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, ans=0; cin >> n;
	string s; cin >> s;
	for (int i=0; i<n-1; i++)
	{
		if (s[i]=='A' && s[i+1]=='B' && s[i+2]=='C')
			ans++;
	}
	cout<<ans<<"\n";
	return 0;
}