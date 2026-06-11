#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int main(void)
{
	int x,y,i,flg,sum,k;
	scanf("%d %d",&x,&y);
	flg=0;
	for(i=0;i<x+1;i++){
		k=x-i;
		if(i*2+4*k==y){
			flg=1;
			break;
		}
	}
	if(flg==1)	printf("Yes\n");
	else	printf("No\n");
	return 0;
}
