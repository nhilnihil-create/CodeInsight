#include<iostream>
#include<cstdio> 
using namespace std;

const int MAXN=300005;
int X[MAXN],Y[MAXN];
struct square
{
	int x,y;
}sq[MAXN];

int main()
{
	//1.输入 
	int H,W,M;
	scanf("%d%d%d",&H,&W,&M);
	//2.统计目标 
	int max_x=0,max_y=0;
	int u,v;
	for(int i=1;i<=M;++i)
	{
		scanf("%d%d",&u,&v);
		++X[u];++Y[v];
		sq[i].x=u;
		sq[i].y=v;
	}
	//3.搜索最大目标数 
	for(int i=1;i<=H;++i)
		if(X[i]>max_x) max_x=X[i];	
	for(int i=1;i<=W;++i)
		if(Y[i]>max_y) max_y=Y[i];
	//4.找出最大行数 
	int x_=0,y_=0;
	for(int i=1;i<=H;++i)
		if(X[i]==max_x) x_++;
	for(int i=1;i<=W;i++)
		if(Y[i]==max_y) y_++;
	int cnt=0;
	for(int i=1;i<=M;++i)
		if(X[sq[i].x]==max_x && Y[sq[i].y]==max_y) ++cnt;
	if(cnt==x_*y_) printf("%d",max_x+max_y-1);
	else printf("%d",max_x+max_y);	
	return 0;   
 } 