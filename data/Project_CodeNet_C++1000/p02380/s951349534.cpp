#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long > vll;
typedef vector< vi > vvi;
int main() {
	double a, b, S, L, h, C, c;
	cin >> a >> b >> C;
	C = C*acos(-1) / 180.0;
	S = a*b*sin(C)*0.5;
	h = b*sin(C);
	c = pow(h, 2) + pow(a - b*cos(C), 2);
	c = pow(c, 0.5);
	L = a + b + c;
	printf("%.6lf\n", S);
	printf("%.6lf\n", L);
	printf("%.6lf\n", h);
}