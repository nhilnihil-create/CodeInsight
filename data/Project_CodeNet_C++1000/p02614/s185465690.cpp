#include<bits/stdc++.h>
using namespace std;
int main()
{
	int m,n,k;
	cin>>m>>n>>k;
	vector<string> s(m);
	for(int i=0;i<m;i++)
	cin>>s[i];
	int ans=0;
	for(int i=0;i<(1<<m);i++)
	for(int j=0;j<(1<<n);j++)
	{
		int c=0;
		for(int o=0;o<m;o++)
		for(int p=0;p<n;p++){
			if (i>>o&1) continue;
			if (j>>p&1) continue;
			if (s[o][p]=='#') c++;
		}
		if(c==k)
		ans++;
	}
	cout<<ans<<endl;
} 
