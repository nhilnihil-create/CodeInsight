#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue>
#define ll long long
using namespace std;

ll n;
char x[23333];
ll cb;
ll ans;

int main()
{
	cin>>n>>x+1;
	for(int i=1;i<=n;i++)
		if(x[i]=='B') cb++;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
		{
			if(x[i]=='B' || x[j]=='B' || x[i]==x[j]) continue;
			ans+=cb;
			if((j-i+1)%2)
				if(x[(i+j)/2]=='B')
					ans--;
			if(i-(j-i)>0 && x[i-(j-i)]=='B')
				ans--;
			if(x[j+(j-i)]=='B')
				ans--;
		}
	cout<<ans;
	return 0;
}