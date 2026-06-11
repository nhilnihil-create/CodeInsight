#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main(){
	double x1,x2,y1,y2,X,Y,ans;
	cin >> x1 >> y1 >> x2 >> y2;
	X=pow(x1-x2,2);
    Y=pow(y1-y2,2);

	ans = sqrt(X+Y);

	printf("%f\n",ans);

	return 0;
}