#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string.h>
#include <string>
#include <vector>
#include <limits.h>
#include <stack>
#include <queue>
#include <cstdlib>
#define maxn 10000000
#define pi acos(-1)
#define ll long long
using namespace std;
struct node{
	double x;
	double y;
};
void solve(int n,node a,node b)
{
	if(n==0)return;
	node t,s,u;
	double th=M_PI*60.0/180.0;  //将单位从度变为弧度；
	
	s.x=(2.0*a.x+1.0*b.x)/3.0;
	s.y=(2.0*a.y+1.0*b.y)/3.0;
	t.x=(1.0*a.x+2.0*b.x)/3.0;
	t.y=(1.0*a.y+2.0*b.y)/3.0;
	u.x=(t.x-s.x)*cos(th)-(t.y-s.y)*sin(th)+s.x;///旋转矩阵；
	u.y=(t.x-s.x)*sin(th)+(t.y-s.y)*cos(th)+s.y;
	
	solve(n-1, a, s);
	printf("%.8lf %.8lf\n",s.x,s.y);
	solve(n-1, s, u);
	printf("%.8lf %.8lf\n",u.x,u.y);
	solve(n-1, u, t);
	printf("%.8lf %.8lf\n",t.x,t.y);
	solve(n-1, t, b);
	
}
int main()
{
	node a,b;
	int n;
	cin>>n;
	a.x=0;
	a.y=0;
	b.x=100;
	b.y=0;
	printf("%.8lf %.8lf\n",a.x,a.y);
//	cout<<a.x<<" "<<a.y<<endl;
	solve(n, a, b);
	printf("%.8lf %.8lf\n",b.x,b.y);
//	cout<<b.x<<" "<<b.y<<endl;
	return 0;
}
