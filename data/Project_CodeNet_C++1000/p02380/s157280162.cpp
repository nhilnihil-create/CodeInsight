#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<stdio.h>
#include<cmath>
#include<vector>
#include<utility>
#include<stack>
#include<queue>
#include<list>
#include<bitset>
#include<functional>

#define FOR(i, a, b) for(int i=(a);i<=(b);i++)
#define RFOR(i, a, b) for(int i=(a);i>=(b);i--)
#define MOD 1000000007
#define INF 1000000000
#define PI 3.14159265358979

using namespace std;
typedef pair<int, int> P;

int main(void) {
	double a, b, c;
	double s,l, h;
	double si ,co;

	cin >> a >> b >> c;
	si = sin(PI*c/180);
	co = cos(PI*c/180);
	s = a*b*si / 2;
	l = a + b + sqrt(a*a + b*b - 2 * a*b*co);
	h = 2 * s / a;


	printf("%.10lf\n", s);
	printf("%.10lf\n", l);
	printf("%.10lf\n", h);
	return 0;
}
