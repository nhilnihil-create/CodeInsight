#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

typedef long long LL;
const int M=105;

struct Point
{
	int x,y;
	Point(int x=0,int y=0)
		:x(x),y(y){}
	void read()
	{
		scanf("%d%d",&x,&y);
	}
	Point operator+=(const Point &B)
	{
		x+=B.x; y+=B.y;
		return *this;
	}
	Point operator+(const Point &B) const
	{
		Point ans=*this;
		return ans+=B;
	}
	// bool operator<(const Point &B) const
	// {

	// }
	LL operator*(const Point &B) const
	{
		return (LL)x*B.x+(LL)y*B.y;
	}
	LL operator^(const Point &B) const
	{
		return (LL)x*B.y-(LL)y*B.x;
	}
	double len()
	{
		return sqrt((double)x*x+(double)y*y);
	}
	void print()
	{
		cout<<x<<" "<<y<<endl;
	}
}p[M];

int main()
{
	int n; scanf("%d",&n);
	for(int i=0;i<n;i++)
		p[i].read();
	double ans=0.0;
	for(int i=0;i<n;i++)
		for(int j=i;j<n;j++)
		{
			int u=i,v=j;
			if((p[u]^p[v])==0&&(p[u].x^p[v].x)<0) continue;
			if((p[u]^p[v])<0) swap(u,v);
			Point sum;
			for(int k=0;k<n;k++)
			{
				if(((p[u]^p[k])>0 && (p[v]^p[k])<0)
					|| ((p[u]^p[k])==0 && (p[u]*p[k])>0)
					|| ((p[v]^p[k])==0 && (p[v]*p[k])>0))
				{
					//cout<<k<<" ";
					sum+=p[k];
				}
					
			}
			// cout<<endl;
			// cout<<i<<" "<<j<<endl;
			// sum.print();
			// cout<<endl;
			ans=max(ans,sum.len());
		}
	printf("%.15f\n",ans);
	return 0;
}