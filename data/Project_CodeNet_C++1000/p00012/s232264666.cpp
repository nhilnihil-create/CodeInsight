#include<iostream>
#include<complex>
using namespace std;

typedef complex<double> P;

double cross(const P& a, const P& b) {
	return imag(conj(a)*b);
}
double dot(const P& a, const P& b) {
	return real(conj(a)*b);
}

int ccw(P a, P b, P c) {
	b -= a; c -= a;
	if (cross(b, c) > 0)		return +1;		// counter clockwise
	if (cross(b, c) < 0)		return -1;		// clockwise
	if (dot(b, c) < 0)		return +2;		// c--a--b on line
	if (norm(b) < norm(c))	return -2;		// a--b--c on line
	return 0;
}

int main(){
	P p[3],t;
	while(cin >> p[0].real() >> p[0].imag() >> p[1].real() >> p[1].imag() >> p[2].real() >> p[2].imag() >> t.real()>> t.imag()){
		int x=0;
		for(int i=0;i<3;i++) x += ccw(p[i],p[(i+1)%3],t);
		if(x==3||x==-3) cout<<"YES"<<endl;
		else cout<< "NO" <<endl;
		}
	return 0;
}