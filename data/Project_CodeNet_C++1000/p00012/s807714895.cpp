
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <stack>
#include <cctype>
#include <complex>
#include <vector>
#include <algorithm>

using namespace std;


bool solve(){
	complex<double> a,b,c,p;
	while(cin>> a.real()>> a.imag()){
		cin>> b.real()>> b.imag();
		cin>> c.real()>> c.imag();
		cin>> p.real()>> p.imag();
		
		complex<double> B,C,P;
		B = b - a;
		C = c - a;
		P = p - a;
		double b1 = B.real();
		double b2 = B.imag();
		double c1 = C.real();
		double c2 = C.imag();
		double p1 = P.real();
		double p2 = P.imag();
		
		//p = xB+yC
		double x = (p1*c2-p2*c1) / (b1*c2-b2*c1);
		double y = (p2*b1-p1*b2) / (b1*c2-b2*c1);
		
		if(0<x && 0<y && 0<x+y && x+y<1){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	
	return true;
}

int main(){
	cout.setf(ios::fixed);
	cout.precision(5);
	solve();

	return 0;
}

 