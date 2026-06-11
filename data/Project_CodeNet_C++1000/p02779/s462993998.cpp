#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=2e5+10;

int main()
{
	int N,pre[maxn];
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%d",&pre[i]);
	sort(pre,pre+N);
	for(int i=0;i<N-1;i++)
	{
		if(pre[i]==pre[i+1])
		{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}