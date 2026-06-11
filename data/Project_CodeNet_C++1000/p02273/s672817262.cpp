#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double pi = acos(-1);
void koch(double x1, double y1, double x2, double y2, int n){
	double tx1 = (2*x1 + x2) / 3.0;
	double ty1 = (2*y1 + y2) / 3.0;
	double tx2 = (x1 + 2*x2) / 3.0;
	double ty2 = (y1 + 2*y2) / 3.0;

	
	if(n > 0){
		koch(x1, y1, tx1, ty1, n-1);
		cout << setprecision(10) << fixed;
		cout << tx1 << " " << ty1 << endl;
	
		double ux = tx1 + (tx2-tx1) * cos(pi/3.0) - (ty2-ty1) * sin(pi/3.0);
		double uy = ty1 + (tx2-tx1) * sin(pi/3.0) + (ty2-ty1) * cos(pi/3.0);
	
		koch(tx1, ty1, ux, uy, n-1);
		cout << ux << " " << uy << endl;

		koch(ux, uy, tx2, ty2, n-1);
		cout << tx2 << " " << ty2 << endl; 

		koch(tx2, ty2, x2, y2, n-1);
	}	

}

int main(){
	int n;
	cin >> n;
	cout << setprecision(10) << fixed;	
	cout << 0.0 << " " << 0.0 << endl;	
	koch(0.0, 0.0, 100.0, 0.0, n);
	cout << 100.0 << " " <<  0.0 << endl;
	return 0; 
	 

}