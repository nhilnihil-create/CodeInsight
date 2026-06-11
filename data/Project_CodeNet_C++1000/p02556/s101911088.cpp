#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
struct node
{
	int x,y;
}a[200001];
int x[200001],y[200001];
int main()
{
	int n;
	scanf("%d",&n);
	int tot=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
		x[++tot]=a[i].x+a[i].y;
		y[tot]=a[i].x-a[i].y;
	}
	sort(x+1,x+tot+1);
	sort(y+1,y+tot+1);
	int x1=x[1]-x[n],x2=x[n]-x[1],y1=y[1]-y[n],y2=y[n]-y[1];
	printf("%d",max(x1,max(x2,max(y1,y2))));
	return 0;
} 