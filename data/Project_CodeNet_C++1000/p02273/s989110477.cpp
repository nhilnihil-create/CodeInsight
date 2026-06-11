#include <cstdio>
#include<iostream>
#include<cmath>

#define NMAX 1000000
#define PI 3.14159265358979323846264338327950288
#define SI (PI*60.0)/180.0
using namespace std;

void koch(double p1x,double p1y,double p2x,double p2y,int n){
	if(n==0){
		printf("%.8f %.8f\n",p1x,p1y);
	}
	else{
	double sx=((p2x-p1x)/3)+p1x;
	double sy=((p2y-p1y)/3)+p1y;
	double tx=(2*(p2x-p1x)/3)+p1x;
	double ty=(2*(p2y-p1y)/3)+p1y;
	double ux=((tx-sx)*cos(SI)-(ty-sy)*sin(SI))+sx;
	double uy=((tx-sx)*sin(SI)+(ty-sy)*cos(SI))+sy;
	koch(p1x,p1y,sx,sy,n-1);
	koch(sx,sy,ux,uy,n-1);
	koch(ux,uy,tx,ty,n-1);
	koch(tx,ty,p2x,p2y,n-1);
	}
	return;
}

int main(){
	std::ios_base::sync_with_stdio(false);

	int n;

	cin>>n;
    koch(0,0,100,0,n);
	printf("%.8f %.8f\n",100.0,0.0);
    return 0;
}