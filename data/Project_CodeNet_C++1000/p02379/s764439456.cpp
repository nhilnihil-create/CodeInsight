
#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<iomanip>
using namespace std;

int main() {
	double x1, x2, y1, y2,ans,a;
	cin >> x1 >> y1 >> x2 >> y2;
	a = (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
	ans = sqrt(a);
	cout << fixed<< setprecision(6)<<ans;
	return 0;
}

