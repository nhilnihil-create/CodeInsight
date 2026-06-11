#include<iostream>
#include<cmath>
using namespace std;

double p1[2]={0.0,0.0},p2[2]={100.0,0.0};

#define A 1.0471975511965

void koch(int d,double p1[],double p2[]){
	if(d==0){return;}
	double p3[2],p4[2],p5[2];
	p3[0]=p1[0]+(p2[0]-p1[0])*1.0/3.0;
	p3[1]=p1[1]+(p2[1]-p1[1])*1.0/3.0;
	p5[0]=p1[0]+(p2[0]-p1[0])*2.0/3.0;
	p5[1]=p1[1]+(p2[1]-p1[1])*2.0/3.0;
	p4[0]=(p5[0]-p3[0])*cos(A)-(p5[1]-p3[1])*sin(A)+p3[0];
	p4[1]=(p5[0]-p3[0])*sin(A)+(p5[1]-p3[1])*cos(A)+p3[1];
	koch(d-1,p1,p3);
	cout<<p3[0]<<' '<<p3[1]<<endl;
	koch(d-1,p3,p4);
	cout<<p4[0]<<' '<<p4[1]<<endl;
	koch(d-1,p4,p5);
	cout<<p5[0]<<' '<<p5[1]<<endl;
	koch(d-1,p5,p2);
}

int main(){
	int n;
	cin>>n;
	cout<<p1[0]<<' '<<p1[1]<<endl;
	koch(n,p1,p2);
	cout<<p2[0]<<' '<<p2[1]<<endl;
	return 0;
}