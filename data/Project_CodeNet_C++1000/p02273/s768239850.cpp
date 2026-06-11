#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
struct Point{
	double x,y;
};
void koch(int n, Point p1, Point p2){
	if(n==0){
		//printf("%f %f \n", p2.x, p2.y);
		return;
	}
	Point s,t,u;
	double co=0.5;
	double si=sqrt(3)/2;
	s.y=(2*p1.y+p2.y)/3;
	s.x=(2*p1.x+p2.x)/3;
	t.y=(p1.y+2*p2.y)/3;
	t.x=(p1.x+2*p2.x)/3;
	u.x=(t.x-s.x)*co-(t.y-s.y)*si+s.x;
	u.y=(t.x-s.x)*si+(t.y-s.y)*co+s.y;
	koch(n-1, p1, s);
	printf("%f %f \n", s.x, s.y);
	koch(n-1, s, u);
	printf("%f %f \n", u.x, u.y);
	koch(n-1, u, t);
	printf("%f %f \n", t.x, t.y);
	koch(n-1, t, p2);
	//printf("%f.8 %f .8\n", p2.x, p2.y);
}
int main(){
	Point p1,p2;
	p1.x=0;
	p1.y=0;
	p2.x=100;
	p2.y=0;
	int n;
	scanf("%d", &n);
	printf("%f %f \n", p1.x, p1.y);
	koch(n,p1,p2);
	printf("%f %f \n", p2.x, p2.y);
	return 0;
}
