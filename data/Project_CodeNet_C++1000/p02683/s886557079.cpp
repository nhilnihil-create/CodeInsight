#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=0x3f3f3f3f;
int bookre[15];
struct Node{
	int costs;
	int ar[15];
}node[15];
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&node[i].costs);
		for(int j=0;j<m;j++)scanf("%d",&node[i].ar[j]);
	}
	int ans=N;
	for(int i=0;i<(1<<n);i++){
		int sum=0;
		memset(bookre,0,sizeof(bookre));
		for(int j=0;j<n;j++){
			if((i>>j)&1){
				sum+=node[j].costs;
				for(int c=0;c<m;c++)bookre[c]+=node[j].ar[c];
			}
		}
		bool flag=true;
		for(int j=0;j<m;j++){
			if(bookre[j]<k){
				flag=false;
				break;
			}
		}
		if(flag)ans=min(ans,sum);
	}
	if(ans==N)printf("-1\n");
	else printf("%d\n",ans);
}