#include<iostream>
#include<cmath>
using namespace std;

typedef struct{
	long double x;
	long double y;
}Coordinate;

void koch(int,Coordinate,Coordinate);
Coordinate Evaluate_u(Coordinate,Coordinate);
void print(Coordinate);

int main(){
	int n;
	cin>>n;
	Coordinate C_i,C_e;
	C_i.x = 0.0;C_i.y = 0.0;
	C_e.x = 100.0;C_e.y = 0.0;

	cout<<0.0<<" "<<0.0<<endl;
	koch(n,C_i,C_e);
	cout<<100.0<<" "<<0.0<<endl;

	cin.get();
	cin.get();
}

void koch(int d,Coordinate p1,Coordinate p2){
	if(d==0) return ;
	
	Coordinate s,t,u;
	s.x = (p1.x*2.0+p2.x*1.0)/3.0;
	s.y = (p1.y*2.0+p2.y*1.0)/3.0;
	t.x = (p1.x*1.0+p2.x*2.0)/3.0;
	t.y = (p1.y*1.0+p2.y*2.0)/3.0;
	u = Evaluate_u(s,t);
	
	koch(d-1,p1,s);
	print(s);
	koch(d-1,s,u);
	print(u);
	koch(d-1,u,t);
	print(t);
	koch(d-1,t,p2);
}

Coordinate Evaluate_u(Coordinate s,Coordinate t){
	Coordinate u;
	const double rad = 60.0*3.14159/180.0;
	u.x = (t.x-s.x)*cos(rad)-(t.y-s.y)*sin(rad)+s.x;
	u.y = (t.x-s.x)*sin(rad)+(t.y-s.y)*cos(rad)+s.y;
	return u;
}

void print(Coordinate c){
	cout<<c.x<<" "<<c.y<<endl;
}