#include<bits/stdc++.h>
using namespace std;
long long zuo[2005][2005],you[2005][2005],shang[2005][2005],xia[2005][2005];
long long H,W;
char a[2005][2005];
int main()
{
	char t;
	scanf("%lld%lld",&H,&W);
	for(int i=1;i<=H;++i)
		for(int j=1;j<=W;++j)
		    scanf(" %c",&a[i][j]);
	for(int i=1;i<=H;++i)
		for(int j=1;j<=W;++j)
			if(a[i][j-1]=='.') zuo[i][j]=zuo[i][j-1]+1; 
	for(int i=1;i<=W;++i)
		for(int j=1;j<=H;++j)
			if(a[j-1][i]=='.') shang[j][i]=shang[j-1][i]+1; 
	for(int i=H;i>=1;--i)
	    for(int j=W;j>=1;--j)
	        if(a[i][j+1]=='.') you[i][j]=you[i][j+1]+1;
	for(int i=W;i>=1;--i)
	    for(int j=H;j>=1;--j)
	        if(a[j+1][i]=='.') xia[j][i]=xia[j+1][i]+1;
	long long ans=0;
	for(int i=1;i<=H;++i)
	{
		for(int j=1;j<=W;++j)
		{
			if(a[i][j]!='.') continue;
			ans=max(ans,zuo[i][j]+you[i][j]+shang[i][j]+xia[i][j]+1);
	    }
	}
	 cout<<ans<<endl;
	return 0;
 } 