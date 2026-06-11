#include<bits/stdc++.h>
#define ll long long
#define MAX 1000005
#define MOD (ll)(1e9+7)
using namespace std;

int main()	
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	ll ans=0;
	for(int i=0; i<n;)	{
		int x=s[i];
		while(s[i]==x)	{
			i++;
		}
		ans++;
	}
	cout << ans << endl;
	return 0;
}