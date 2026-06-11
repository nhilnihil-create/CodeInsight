#include <iostream>
#include <algorithm>
using namespace std;

double check(double x1, double y1, double x2, double y2, double x3, double y3){
	double ab = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	double bc = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
	double ca = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
	double s = (ab + bc + ca) * 0.5;
	double S = sqrt(s * (s - ab) * (s - bc) * (s - ca));
	return S;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	double x1, y1, x2, y2, x3, y3, xp, yp;
	while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> xp >> yp){
	
	double abc = check(x1, y1, x2, y2, x3, y3);
	double abp = check(x1, y1, x2, y2, xp, yp);
	double bcp = check(x2, y2, x3, y3, xp, yp);
	double cap = check(x3, y3, x1, y1, xp, yp);
	
	double var = abc - (abp + bcp + cap);
	if(var <= 0.001 && var >= -0.001){
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	}
	
	return 0;
}