#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef pair<double,double> pdd;

void make(pdd s,pdd t,int k)
{
	if(k==0) 
	{
		printf("%.8f %.8f\n",s.x,s.y);
		return ;
	}
	pdd a,b,c;
	a.x=(s.x*2+t.x)/3;a.y=(s.y*2+t.y)/3;
	c.x=(t.x*2+s.x)/3;c.y=(t.y*2+s.y)/3;
	b.x=(s.x+t.x)/2-(t.y-s.y)/(2*sqrt(3));b.y=(s.y+t.y)/2+(t.x-s.x)/(2*sqrt(3));
	make(s,a,k-1);
	make(a,b,k-1);
	make(b,c,k-1);
	make(c,t,k-1);
}

int main()
{
	int n;
	scanf("%d",&n);
	pdd s(0,0),t(100,0);
	make(s,t,n);
	printf("%.8f %.8f\n",100.0,0.0);
}