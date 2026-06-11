#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> PII;
const int M=105;

int main()
{
	int n,k; scanf("%d%d",&n,&k);
	if(k>(n-1)*(n-2)/2)
	{
		puts("-1");
		return 0;
	}
	vector<PII> ans;
	for(int i=1;i<n;i++)
		ans.push_back({i,n});
	k=(n-1)*(n-2)/2-k;
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<n&&k;j++,k--)
		{
			ans.push_back({i,j});
		}
		if(!k) break;
	}
	printf("%d\n",ans.size());
	for(auto p:ans)
		printf("%d %d\n",p.first,p.second);
	return 0;
}
