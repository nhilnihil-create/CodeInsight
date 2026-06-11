#include<cstdio>
using namespace std;
int main()
{
	int n,m,a,i,x;
	x=0;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d",&a);
		x+=a;
	}
	n-=x;
	if(n<0) printf("-1\n");
	else printf("%d\n",n);
	return 0;
}
