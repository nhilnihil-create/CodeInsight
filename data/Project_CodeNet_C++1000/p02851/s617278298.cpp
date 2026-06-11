#include "bits/stdc++.h"
using namespace std;

const int N=2e5+20;

int n,k,x;
map <int,queue <int>> m;
long long s,ans;

int main()
{
	scanf("%d%d",&n,&k);
	m[0].push(0);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		s+=x;

		int r=(s-i)%k;
		m[r].push(i);

		while(i-m[r].front()>=k) m[r].pop();
		ans+=m[r].size()-1;
	}
	printf("%lld",ans);
}