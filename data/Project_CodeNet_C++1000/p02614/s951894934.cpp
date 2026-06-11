#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
int c[40],num[10][10],b[10][10];
string s[10];
int main()
{
cin>>n>>m>>k;
for(int i=1;i<=n;i++)cin>>s[i];
for(int i=1;i<=n;i++)
	for(int j=0;j<m;j++)
	if(s[i][j]=='.')num[i][j+1]=0; else num[i][j+1]=1;
ans=0;
int maxi=1;
for(int i=1;i<=n+m;i++) maxi=maxi*2;
for(int l=0;l<maxi;l++)
	{
	int opt=l,top=0;
	memset(c,0,sizeof(c));
	while(opt>0)
		{
		c[++top]=opt&1;
		opt>>=1;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)b[i][j]=num[i][j];
	for(int i=1;i<=top;i++)
		if(i<=n){
			if(c[i]==1)
			for(int j=1;j<=m;j++)b[i][j]=2;
		}
		else if(c[i]==1)
			for(int j=1;j<=n;j++)b[j][i-n]=2;
	int tot=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)if(b[i][j]==1)tot++;
	if(tot==k)ans++;
	}
cout<<ans;
return 0;
}