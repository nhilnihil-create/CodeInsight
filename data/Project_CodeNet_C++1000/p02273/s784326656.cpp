#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

void coch(double sx,double sy,double tx,double ty,int i,int n){
	if(i == n){
		return;
	}else{
		double xx = (tx-sx) / 3.0;	double yy = (ty-sy) / 3.0;
		double a = sqrt(3.0) * xx / 2.0;	double b = xx / 2.0;
		double c = sqrt(3.0) * yy / 2.0;	double d = yy / 2.0;
		coch(sx,sy,sx+xx,sy+yy,i+1,n);
		printf("%.8lf %.8lf\n",sx+xx,sy+yy);
		coch(sx+xx,sy+yy,sx+xx + b - c,sy + yy + a + d,i+1,n);
		printf("%.8lf %.8lf\n",sx+xx + b - c,sy+yy + a + d);
		coch(sx+xx + b - c,sy +yy + a + d,sx + 2.0*xx ,sy + 2.0*yy,i+1,n);
		printf("%.8lf %.8lf\n",sx + 2.0*xx ,sy + 2.0*yy);
		coch(sx + 2.0*xx ,sy + 2.0*yy,tx,ty,i+1,n);
	}
}

int main()
{
	int n;
	cin >> n;
	printf("0.00000000 0.00000000\n");
	coch(0.0,0.0,100.0,0.0,0,n);
	printf("100.00000000 0.00000000\n");
}