#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define l long long
#define itn int
int b[3005];
int main()
{
	int n;
	itn ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&b[i]);
	sort(b,b+n);
	for(int i=0;i<n;i++)
	{
		for(itn c=i+1;c<n;c++)
		{
			int least=c+1;
			int o=lower_bound(b,b+n,b[i]+b[c])-b;
			ans+=o-least;
		}
	}
	cout<<ans<<endl;
	return 0;
}