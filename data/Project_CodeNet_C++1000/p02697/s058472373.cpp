#include<bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
	//freopen("in.txt","r",stdin);
	scanf("%d %d",&n,&m);
	if(n&1){
		for(int i=1,j=n;i<=m;++i,--j) printf("%d %d\n",i,j);
	}
	else{
		for(int i=1,j=n;i<=m;++i,--j){
			printf("%d %d\n",i,j);
			if(i==n>>2) --j;
		}
	}
}