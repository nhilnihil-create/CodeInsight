#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main(){
	long double x1,y1,x2,y2,ans;
	cin >> x1 >> y1 >> x2 >> y2;
	ans = (x2 - x1)*(x2 - x1)+(y2 - y1)*(y2 - y1);
	ans = sqrtl(ans);
	cout << setprecision(18) << ans << "\n";
	return 0;
}