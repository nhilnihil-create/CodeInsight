#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
	int n,i,j,a=0,b=0,c=0;
	cin>>n;
	string s;
	cin>>s;
	for(i=0;i<n;++i)
	{
		if(s[i]=='R')		++a;
		if(s[i]=='G')		++b;
		if(s[i]=='B')		++c;
	}
	ll ans = 1ll*a*b*c,cnt=0ll;
//	cout<<ans<<"\n";
	for(i=0;i<n;++i)
	{
		for(j=i+1;j<n;++j)
		{
			if(j+j-i<n&&s[i]!=s[j])
			{
				if(s[j+j-i]!=s[i]&&s[j+j-i]!=s[j])
				{
				//	printf("%d %d %d\n",i,j,j+j-i);
					++cnt;
				}
			}
		}
	}
	printf("%lld",ans-cnt);
}