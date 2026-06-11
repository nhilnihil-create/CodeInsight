#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll ans = 0,n;
	cin >> n;
	string s;
	cin >> s;

	for(int i = 0;i<n;i++)
	{
		ll l = 0;
		for(int j = 0;j+i<n;j++)
		{
			if(s[j]==s[i+j])
			{
				l = min<ll>(l+1,i);
			}
			else l = 0;
			ans = max(ans,l);
		}
	}
	cout << ans << endl;
}
