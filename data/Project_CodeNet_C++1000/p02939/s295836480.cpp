#include<bits/stdc++.h>
using namespace std;
const int maxn=200100;
char s[maxn];int n,f[maxn][2];
int main()
{
	scanf("%s",s+1);n=strlen(s+1);
	for(int i=1;i<=n;i++) f[i][0]=f[i][1]=-n;
	f[1][0]=1;f[2][1]=1;
	for(int i=1;i<=n;i++)
	{
		if(i+2<=n)
		{
			f[i+2][1]=max(f[i+2][1],f[i][0]+1);
			if(s[i-1]!=s[i+1]||s[i]!=s[i+2])
				f[i+2][1]=max(f[i+2][1],f[i][1]+1);
		}
		if(i+1<=n)
		{
			f[i+1][0]=max(f[i+1][0],f[i][1]+1);
			if(s[i]!=s[i+1])
				f[i+1][0]=max(f[i+1][0],f[i][0]+1);
		}
	}
	cout<<max(f[n][0],f[n][1])<<endl;
}