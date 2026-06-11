#include <iostream>
#include <cmath>
using namespace std;

void Kochcurve(double stX, double stY, double edX, double edY, int n){
	if(n!=0){
		double sX, sY, tX, tY, uX, uY;
		sX = stX + (edX - stX) / 3;
		sY = stY + (edY - stY) / 3;
		tX = stX + (edX - stX) * 2 / 3;
		tY = stY + (edY - stY) * 2 / 3;
		uX = sX + (tX - sX) / 2 - (tY - sY) * sqrt(3) / 2;
		uY = sY + (tX - sX) * sqrt(3) / 2 + (tY - sY) / 2;
		
		Kochcurve(stX,stY,sX,sY,n-1);
		cout << sX << " " << sY << endl;
		Kochcurve(sX,sY,uX,uY,n-1);
		cout << uX << " " << uY << endl;
		Kochcurve(uX,uY,tX,tY,n-1);
		cout << tX << " " << tY << endl;
		Kochcurve(tX,tY,edX,edY,n-1);
	}
}

int main() {
	int n;
	cin>>n;
	cout << 0 << " " << 0 << endl;
	Kochcurve(0,0,100,0,n);
	cout << 100 << " " << 0 << endl;
	return 0;
}