#include <bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	double rad=c*M_PI/180.0;
	cout<<fixed<<setprecision(8)<<a*b*sin(rad)/2<<endl<<a+b+sqrt(a*a+b*b-2*a*b*cos(rad))<<endl<<b*sin(rad)<<endl;
	return 0;
}

