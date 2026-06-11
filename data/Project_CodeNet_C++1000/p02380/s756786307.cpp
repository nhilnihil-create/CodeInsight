#include <bits/stdc++.h>
using namespace std;

int main(){
	double a,b,c,d,e,f,S,l,h=0;
	cin>>a>>b>>c;
	e=sin(c*M_PI/180);
	f=cos(c/180*M_PI);
	S=(a*b*e)/2;
	d=sqrt(a*a+b*b-(a*b*f)*2);
	l=a+b+d;
	h=(S*2)/a;
	cout <<setprecision(12)<<S<<" "<<l<<" "<<h <<endl;
	return 0;
}