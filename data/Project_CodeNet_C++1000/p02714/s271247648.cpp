#include<bits/stdc++.h>
using namespace std;

long long int n,r[4010],g[4010],b[4010],i,ans,j;
string s;

signed main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>s;
	r[0]=0;b[0]=0;g[0]=0;
	for (i=1;i<n+1;i++)
	{
		r[i]=r[i-1];
		g[i]=g[i-1];
		b[i]=b[i-1];
		if (s[i-1]=='R') r[i]++;
		if (s[i-1]=='G') g[i]++;
		if (s[i-1]=='B') b[i]++;
	}
	ans=0;
	for (i=2;i<n;i++) for (j=i+1;j<n+1;j++) if (s[i-1]!=s[j-1])
	{
		if ((s[i-1]=='R' && s[j-1]=='G') || (s[i-1]=='G' && s[j-1]=='R'))
		{
			ans=ans+b[i-1];
			if (2*i-j>0) if (s[2*i-j-1]=='B') ans--;
		}
		if ((s[i-1]=='G' && s[j-1]=='B') || (s[i-1]=='B' && s[j-1]=='G'))
		{
			ans=ans+r[i-1];
			if (2*i-j>0) if (s[2*i-j-1]=='R') ans--;
		}
		if ((s[i-1]=='R' && s[j-1]=='B') || (s[i-1]=='B' && s[j-1]=='R'))
		{
			ans=ans+g[i-1];
			if (2*i-j>0) if (s[2*i-j-1]=='G') ans--;
		}
	}
	cout<<ans;
}
