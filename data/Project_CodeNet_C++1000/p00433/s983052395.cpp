#include <cstdio>

int main(){
	int t,a=0,b=0;
	for(int i=0;i<4;i++)scanf("%d",&t),a+=t;
	for(int i=0;i<4;i++)scanf("%d",&t),b+=t;
	if(a>=b)printf("%d\n",a);
	else printf("%d\n",b);
	return 0;
}