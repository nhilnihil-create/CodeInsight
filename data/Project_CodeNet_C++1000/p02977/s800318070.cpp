#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;
typedef pair<int,int> PII;
int n;
int pos[400050],rnk[400050];
vector<PII> an;
int main()
{
	scanf("%d",&n);
	int k=0;
	while((1<<k)<n)
	{
		++k;
	}
	if(n==(1<<k))
	{
		printf("No\n");
		return 0;
	}
	pos[1]=1;
	an.push_back(make_pair(n+1,3));
	for(int i=1;i<k;++i)
	{
		int m=1<<i;
		an.push_back(make_pair(1<<(i-1),m));
		an.push_back(make_pair(m+n,m+1+n)); 
		for(int j=1;j<m;++j)
		{
			rnk[pos[j]]=j;
		}
		for(int j=1;j<m&&j+m<=n;++j)
		{
			an.push_back(make_pair(m+j+n,rnk[j]));
			an.push_back(make_pair(m+j,m));
			pos[j+m]=j;
			pos[j]=pos[j]+m; 
		}
		pos[m]=m;
	}
	printf("Yes\n");
	for(unsigned int i=0;i<an.size();++i)
	{
		printf("%d %d\n",an[i].first,an[i].second);
	}
	return 0;
} 