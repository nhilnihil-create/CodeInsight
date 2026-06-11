#include <iostream>
#include <cstdio>
#include <complex>
#include <cmath>

using namespace std;
const double eps = 1e-11;

typedef complex<double> xy_t;

double dotProduct(xy_t a, xy_t b){
	return (conj(a) * b).real();
}

double crossProduct(xy_t a, xy_t b){
	return (conj(a) * b).imag();
}

xy_t projection(xy_t p, xy_t b){
	return b*dotProduct(p,b)/norm(b);
}

int main (){
	int N;
	double X[4],Y[4];
	cin >> N;
	for(int t = 0; t < N; ++t){
		for(int i = 0; i < 4; ++i) cin >> X[i] >> Y[i];
		xy_t a[2] = {
			xy_t(X[0],Y[0]) - xy_t(X[1],Y[1]),
			xy_t(X[2],Y[2]) - xy_t(X[3],Y[3]),
		};
		cout << ((abs(crossProduct(a[0],a[1])) < eps) ? "YES" : "NO") << endl;
	}
	return 0;
}