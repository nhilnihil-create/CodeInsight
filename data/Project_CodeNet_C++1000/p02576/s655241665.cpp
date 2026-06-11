#include <stdio.h>
using namespace std;
int main(){
	int n,x,t,ans;
	scanf("%d%d%d",&n,&x,&t);
	ans=(n-1+x)/x*t;
	printf("%d\n",ans);
return 0;
}