#include<bits/stdc++.h>
using namespace std;

void koch(double, double, double, double, int cnt);

int n;

int main(){
	cin >> n;
	printf("%.8f %.8f\n", 0, 0);
	koch(0, 0, 100, 0, 0);
	printf("%.8f %.8f\n", 100.0, 0);
	return 0;
}

void koch(double x1, double y1, double x2, double y2, int cnt){
	if(cnt == n){
		return;
	}
	double sx = (2 * x1 + x2)/3;
	double sy = (2 * y1 + y2)/3;
	double tx = (x1 + x2 * 2)/3;
	double ty = (y1 + y2 * 2)/3;
	
	double vertex_x = sx + (tx - sx)/2 - (ty - sy) * sin(M_PI/3);
	double vertex_y = sy + (tx - sx) * sin(M_PI/3) + (ty - sy)/2;
    
  koch(x1, y1, sx, sy, cnt + 1);
  printf("%.8f %.8f\n", sx, sy); 
  koch(sx, sy, vertex_x, vertex_y, cnt + 1);
  printf("%.8f %.8f\n",vertex_x, vertex_y);
  koch(vertex_x, vertex_y, tx, ty, cnt + 1);
  printf("%.8f %.8f\n", tx, ty);   
  koch(tx, ty, x2, y2, cnt + 1);
}   