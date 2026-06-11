#include <iostream>
#include <cstring>
#include <sstream>
#include <cctype>
#include <cmath>
#include <cstdio>
using namespace std;
#define MPI  3.14159265358979323846


int main(){

	double a, b, C, S, L, h;
	cin >> a >> b >> C ;

	S = a*b*sin(C*MPI / 180.0)/2;
	L = a + b + sqrt(a*a + b*b - 2 * a*b*cos(C*MPI / 180.0));
	h = b*sin(C*MPI / 180.0);

	printf("%.8f\n%.8f\n%.8f\n", S, L, h);

	return 0;
}
