#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct E{
	int x,y;
	bool operator<(E a)
	{
		if(x*x+y*y!=a.x*a.x+a.y*a.y)return x*x+y*y<a.x*a.x+a.y*a.y;
		else return x<a.x;
	}
};
main()
{
	int h,w;
	while(cin>>h>>w,h)
	{
		E a,b,c;
		a.x=h,a.y=w;
		b.x=b.y=150;
		for(int i=1;i<150;i++)for(int j=i+1;j<150;j++)
		{
			c.x=i,c.y=j;
			if(a<c&&c<b)b=c;
		}
		cout<<b.x<<" "<<b.y<<endl;
	}
}
