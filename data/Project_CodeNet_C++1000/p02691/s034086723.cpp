#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,num;
ll ans;
map<int,int> ma,mb;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num);
		ma[i-num]++,mb[i+num]++;
	}
	for(map<int,int>::iterator it=ma.begin();it!=ma.end();it++)
	{
		pair<int,int> pi=*it;
		int a=pi.first,b=pi.second;
		ans+=ll(b)*ll(mb[a]);
	}
	printf("%lld\n",ans);
	return 0;
}