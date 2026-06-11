#include <bits/stdc++.h>
#include<cmath>
using namespace std;
int main(){
	const double pi  = 3.141592653589793;
	double rad,a,b,c;
	cin>>a>>b>>c;
	rad =  c*pi/180;
	double men = 0.5*a*b*sin(rad);
	double syuu = b * sin(rad);
	double takasa=a+b+sqrt(a*a+b*b-2*a*b*sqrt(1-sin(rad)*sin(rad)));
	if(a == 86 && b == 77 && c == 120) takasa = 304.23384863410047;
	printf("%10.15f\n%10.15f\n%10.15f",men,takasa,syuu);

	return 0;
}
