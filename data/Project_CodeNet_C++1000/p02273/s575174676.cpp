#include<stdio.h>
#include<math.h>
/*
Divide a given segment (p1, p2) into three equal segments.
Replace the middle segment by the two sides of an equilateral triangle (s, u, t) of the same length as the segment.
Repeat this procedure recursively for new segments (p1, s), (s, u), (u, t), (t, p2).
*/
void divide(int n,double x1, double y1,double x2, double y2){
	if(n==0){
		if((x1==0&&y1==0)||(x1==100&&y1==0))
			printf("%.8lf %.8lf\n",x1,y1);
		printf("%.8lf %.8lf\n",x2,y2);
		return;
	}
	//
	double th=M_PI*60.0/180.0;
	double sx=(2.0*x1+1.0*x2)/3.0;
    double sy=(2.0*y1+1.0*y2)/3.0;
    double tx=(1.0*x1+2.0*x2)/3.0;
    double ty=(1.0*y1+2.0*y2)/3.0;
    double ux=(tx-sx)*cos(th)-(ty-sy)*sin(th)+sx;
    double uy=(tx-sx)*sin(th)+(ty-sy)*cos(th)+sy;
	divide(n-1,x1,y1,sx,sy);
	//double mid_x = ;//(((x1+x2)/3)+(2*(x1+x2)/3))/2;
	//double mid_y = 
	divide(n-1,sx,sy,ux,uy);
	//divide(n-1,(2*(x1+x2)/3),((y1+y2)/2),x2,y2);
	divide(n-1,ux,uy,tx,ty);
	divide(n-1,tx,ty, x2,y2);
}

int main(){
	int n;
	scanf("%d",&n);
	double x1 = 0,y1 = 0;
	double x2 = 100, y2= 0;
	divide(n,x1,y1,x2,y2);
	return 0;
} 
