#include<cstdio>
#include<cmath>

double getd(double x, double y){
	double r = atan2(y, x) * 180 / M_PI;
	return r;
}

int main(){
	double x1,y1,x2,y2,x3,y3,xp,yp,d1,d2,d3;
	double h;
	while(scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &x1,&y1,&x2,&y2,&x3,&y3,&xp,&yp) + 1){
		x1 -= xp;
		x2 -= xp;
		x3 -= xp;
		y1 -= yp;
		y2 -= yp;
		y3 -= yp;
		d1 = getd(x1,y1);
		d2 = getd(x2,y2);
		d3 = getd(x3,y3);
		if(d1 > d2){
			h = d1;
			d1 = d2;
			d2 = h;
		}
		if(d2 > d3){
			h = d2;
			d2 = d3;
			d3 = h;
			if(d1 > d2){
				h = d1;
				d1 = d2;
				d2 = h;
			}
		}
		d2 -= d1;
		d3 -= d1;
		if(180 > d2){
			if(180 < d3 && d3 < d2 + 180){
				printf("YES\n");
			}else{
				printf("NO\n");
			}
		}else{
			printf("NO\n");
		}
	}
	return 0;
}