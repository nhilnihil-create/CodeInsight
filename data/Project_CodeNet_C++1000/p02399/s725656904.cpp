#include<iostream>
#include<string>
#include<cmath>
#include<queue>
#include<vector>
#include<functional>
#include<algorithm>
#include<cstdio>
using namespace std;
int main() {
	int a, b, d, r;
	long double f;
	cin >> a >> b;
	d = floor(a / b);
	r = a%b;
	f = (long double)a / b;
	printf("%d %d %LF", d, r, f);
	cin >> a;
}