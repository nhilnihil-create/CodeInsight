#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;
int n;

void koch(int time, double lx, double ly, double rx, double ry){
	
		double sx = lx + (rx - lx) / 3;
		double sy = ly + (ry - ly) / 3;
		double ux = sx + (sx - lx) * 1 / 2 - (sy - ly) * sqrt(3)/ 2;
		double uy = sy + (sx - lx) * sqrt(3)/ 2 + (sy - ly) * 1 / 2;
		double tx = lx + (rx - lx) * 2 / 3;
		double ty = ly + (ry - ly) * 2 / 3;
		if(time == n){
		cout << lx << " " << ly << endl;
		cout << sx << " " << sy << endl;
		cout << ux << " " << uy << endl;
		cout << tx << " " << ty << endl;
		}
		else{
			koch(time + 1, lx, ly, sx, sy);
			koch(time + 1, sx, sy, ux, uy);
			koch(time + 1, ux, uy, tx, ty);
			koch(time + 1, tx, ty, rx, ry);
		}
}



int main(){
	cin >> n;
	cout  <<fixed <<setprecision(8);
	double lx = 0;
	double ly = 0;
	double rx = 100;
	double ry = 0;
	if(n == 0){
		cout << lx << " " << ly << endl;
	}
	else{
		koch(1, lx, ly, rx, ry);
	}
	cout << rx << " " << ry << endl;
	return 0;
}