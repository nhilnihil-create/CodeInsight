#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	string t="#"+s;
	vector<int>red(n+1),green(n+1),blue(n+1);
	int sum1=0,sum2=0,sum3=0;
	for(int i=1; i<=n; i++)
	{
		if(t[i]=='R')
		 sum1++;
		if(t[i]=='G')
		 sum2++;
		if(t[i]=='B')
		 sum3++;
		red[i]=sum1;
		green[i]=sum2;
		blue[i]=sum3;
	}
	ll ans=0;
	for(int i=1; i<=n-2; i++)
	{
		for(int j=i+2; j<=n; j++)
		{
			if(t[i]==t[j])
			 continue;
			if(t[i]!='R' && t[j]!='R')
			{
				ans+=red[j]-red[i];
				if((i+j)%2==0)
				{
					if(t[(i+j)/2]=='R')
					 ans--;
				}
			}
			else if(t[i]!='G' && t[j]!='G')
			{
				ans+=green[j]-green[i];
				if((i+j)%2==0)
				{
					if(t[(i+j)/2]=='G')
					 ans--;
				}
			}
			else if(t[i]!='B' && t[j]!='B')
			{
				ans+=blue[j]-blue[i];
				if((i+j)%2==0)
				{
					if(t[(i+j)/2]=='B')
					 ans--;
				}
			}
			
		}
	}
	cout<<ans;
	return 0;
}