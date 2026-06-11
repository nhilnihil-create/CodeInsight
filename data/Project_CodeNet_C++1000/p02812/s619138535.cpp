#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif // ONLINE_JUDGE
	ll times=1;
	// cin>>times;
	while(times--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		int res=0;
		for(int i=0;i<=n-3;i++)
		{
			if(str[i]=='A' && str[i+1]=='B' && str[i+2]=='C')
				res++;
		}
		cout<<res<<"\n";
	}
}