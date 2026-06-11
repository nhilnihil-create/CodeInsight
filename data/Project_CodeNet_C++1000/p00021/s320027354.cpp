#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <complex>

using namespace std;

// deq notes ½Êô½É¨¯éxNgZ http://www.deqnotes.net/acmicpc/2d_geometry/
typedef complex<double> P;

#define EPS (1e-10)
#define EQ(a,b) (abs((a)-(b)) < EPS)

// OÏ (cross product) : a~b = |a||b|sinÆ
double cross(P a, P b) {
	return (a.real() * b.imag() - a.imag() * b.real());
}

// 2¼üÌ½s»è: a//b <=> cross(a, b) = 0
int is_paralell (P a, P b) {
	return EQ ( cross(a, b), 0.0 );
}

int main()
{
	string str = "";
	int n;
	int i,j;

	getline (cin, str );
	stringstream ssn(str);
	ssn >> n;

	for (i = 0; i < n; ++i){

		P p[4];	// A,B,C,D order
		getline (cin, str );
		stringstream ss(str);

		for (j = 0; j < 4; ++j){
			ss >> p[j].real() >> p[j].imag();
		} // end for

		if (is_paralell (p[1] - p[0], p[3] - p[2] ) ) {
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		} // end if

	} // end for
		
	return 0;
}