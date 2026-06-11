#include <bits/stdc++.h>
using namespace std;

int main(){
	double x1, x2, y1, y2;
	double tmp,d;

	cin>>x1>>y1>>x2>>y2;
	tmp = pow((x1 - x2), 2) + pow((y1 - y2), 2);
	d = sqrt(tmp);

	printf("%7lf\n",d );

	return 0;
}