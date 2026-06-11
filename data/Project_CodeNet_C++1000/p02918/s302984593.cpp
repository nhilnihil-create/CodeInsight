#include"bits/stdc++.h"
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif

	int n,k;cin>>n>>k;
	string s;
	cin>>s;
	int ans=0;
	for(int i=0;i<n-1;i++)
	{
		if(s[i]==s[i+1])ans++;
	}

	cout<<min(n-1, 2*k+ans);
}