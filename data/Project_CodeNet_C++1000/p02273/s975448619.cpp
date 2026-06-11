#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct point{
	double x;
	double y;	
};

void print_point(point a){
	printf("%.8f %.8f\n",a.x,a.y);
	return ;
}

void koch(int n ,point a ,point b){
	if(n==0) return ;
	point c,d,e;
	c.x=a.x+(b.x-a.x)/3;
	c.y=a.y+(b.y-a.y)/3;
	e.x=a.x+2*(b.x-a.x)/3;
	e.y=a.y+2*(b.y-a.y)/3;
	d.x=c.x+(e.x-c.x)*cos(M_PI*60/180)+(e.y-c.y)*(-sin(M_PI*60/180));
	d.y=c.y+(e.x-c.x)*sin(M_PI*60/180)+(e.y-c.y)*cos(M_PI*60/180);
	koch(n-1,a,c);
	print_point(c);
	koch(n-1,c,d);
	print_point(d);
	koch(n-1,d,e);
	print_point(e);
	koch(n-1,e,b);
	return;	
}

int main (){
	int n ;
	cin>>n;
	point a,b;
	a.x=0;a.y=0;
	b.x=100;b.y=0;
	print_point(a);
	koch(n,a,b);
	print_point(b);
	return 0;
}
