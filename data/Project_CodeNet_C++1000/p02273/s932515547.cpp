#include<iostream>
#include<cmath>
#include<cstdio>
#include<bits/stdc++.h>

using namespace std;

struct Point{
	double x,y;
}; 

void korch(int d,Point p1,Point p2)
{
	if(d==0)return;
	
	Point s,t,u;
	double th=M_PI * 60.0/180.0;//将单位从度变成弧度
	s.x=(2*p1.x+p2.x)/3;
	s.y=(2*p1.y+p2.y)/3;
	t.x=(p1.x+2*p2.x)/3;
	t.y=(p1.y+2*p2.y)/3;
	u.x=(t.x-s.x)*cos(th)-(t.y-s.y)*sin(th)+s.x;
	u.y=(t.x-s.x)*sin(th)+(t.y-s.y)*cos(th)+s.y;
	 
	korch(d-1,p1,s);
	printf("%.8lf %.8lf\n",s.x,s.y);
	korch(d-1,s,u);
	printf("%.8lf %.8lf\n",u.x,u.y);
	korch(d-1,u,t);
	printf("%.8lf %.8lf\n",t.x,t.y);
	korch(d-1,t,p2);
}

int main()
{
	int n;
	scanf("%d",&n);
	Point p1,p2;
	p1.x=p1.y=0;
	p2.x=100;
	p2.y=0;
	printf("%.8lf %.8lf\n",p1.x,p1.y);
	korch(n,p1,p2);
	printf("%.8lf %.8lf\n",p2.x,p2.y);
	return 0;
}
