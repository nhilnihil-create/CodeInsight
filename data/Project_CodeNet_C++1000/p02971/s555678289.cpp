#include<stdio.h>
int main()
{
	int n,a,x=0,x2=0,y,i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a);
		if(x<a){
			x2=x;
			x=a;
			y=i;
		}
		else if(x2<a) x2=a;
	}
	for(i=0;i<n;i++){
		if(y==i) printf("%d\n",x2);
		else printf("%d\n",x);
	}
	return 0;
}
