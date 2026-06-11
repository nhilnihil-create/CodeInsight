#include<iostream>
#include<cstring>
using namespace std;
#define N 200005
int num[N],d[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;++i) cin>>num[i];
	for(int i=1;i<=k;++i)
	{
		memset(d,0,sizeof(d));
		for(int j=1;j<=n;++j)
		{
			int L=max(1,j-num[j]);
			int R=min(n,j+num[j])+1;
			++d[L];
			--d[R];
		}
		int flag=1;
		for(int j=1;j<=n;++j) 
		{
			num[j]=num[j-1]+d[j];
			if(num[j]!=n) flag=0;
		}
		if(flag) break;
	}
	for(int i=1;i<=n;++i) cout<<num[i]<<" ";
	return 0;
} 