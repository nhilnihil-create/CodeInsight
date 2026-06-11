#include<bits/stdc++.h>
using namespace std;
const long long mod=1000000007;
long long f[1000005][2];
int main()
{
	char ss[100005];
	cin >> ss+1;
	f[0][1]=1;
	f[0][0]=0;
	int n=strlen(ss+1);
	for(int i=1;ss[i];i++)
	{
		f[i][0]=(f[i-1][0]*3)%mod;
		if(ss[i]=='1')
		{
			f[i][1]=(f[i-1][1]*2)%mod;
			f[i][0]+=f[i-1][1];
			f[i][0]=(f[i][0])%mod;
		}
		else
		{
			f[i][1]=f[i-1][1];
		}
	}
	printf("%lld\n",(f[n][1]+f[n][0])%mod);
}
