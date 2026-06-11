#include<bits/stdc++.h>
using namespace std;

int main(){
	cout<<fixed<<setprecision(12);

	double a, b, C, c, S, L, h, rad;

	cin>>a>>b>>C;
	
	rad = C / 180 * acos(-1);

	S = (a * b * sin(rad)) / 2;
	c = sqrt(a * a + b * b -2 * a * b * cos(rad));
	L = a + b + c;
	h = 2 * S / a;
	
	cout<<S<<endl<<L<<endl<<h<<endl;
	
	return 0;	
}
