#include<cstdio>
using namespace std;
int main(void)
{
	int a,b,x,y;
	double p,aa,bb;  
	scanf("%d %d",&a,&b);
	aa=a;
	bb=b;
	x=a/b;
	y=a%b;
	p=aa/bb;
	printf("%d %d %lf\n",x,y,p);
	return 0;
}
	
	