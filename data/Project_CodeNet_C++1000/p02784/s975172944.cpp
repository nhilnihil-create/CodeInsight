#include<cstdio>
using namespace std;
int main()
{
	int i,a,n,b,x[100000];
	scanf("%d %d",&a,&n);
	for(i=0;i<n;i++){
		scanf("%d",&x[i]);
	}
	b=0;
	for(i=0;i<n;i++){
		b+=x[i];
	}
	if(b>=a) printf("Yes\n");
	else printf("No\n");
	return 0;
}