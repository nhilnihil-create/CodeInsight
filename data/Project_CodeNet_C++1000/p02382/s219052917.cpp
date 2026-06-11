#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;

double dis(const vector<double>& x,
	   const vector<double>& y,
	   const double p) {

    const int n = x.size();
    double d = 0.0;

    if( p == -1 ) {
	for(int i=0; i<n; i++) {
	    d = max(d,abs(x[i]-y[i]));
	}
	return d;
    }

    for(int i=0; i<n; i++) {
	d += pow(abs(x[i]-y[i]),p);
    }
    return pow(d,1/p);
}

int main() {
    int n; cin >> n;
    vector<double> x,y;
    for(int i=0; i<n; i++) {
	double t; cin >> t;
	x.push_back(t);
    }
    for(int i=0; i<n; i++) {
	double t; cin >> t;
	y.push_back(t);
    }

    for(int i=1; i<=3; i++)
	printf("%.10f\n",dis(x,y,i));
    printf("%.10f\n",dis(x,y,-1));

}