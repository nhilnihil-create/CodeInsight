#include "bits/stdc++.h"
using namespace std;

int main() {
	double A,B,C;
	double d;
	cin>>A>>B>>C;
	d=(acos(-1)*C)/180;
	printf("%lf\n",A*B*sin(d)/2);
	printf("%lf\n",A+B+sqrt(A*A+B*B-2*A*B*cos(d)));
	printf("%lf\n",B*sin(d));
}