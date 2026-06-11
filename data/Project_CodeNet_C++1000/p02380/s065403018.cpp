#include <iostream>
#include <cstdio>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

#define pi 3.141592653589
#define repeat(i,n) for(int i=0;i<n;i++)

int main()
{
	int a, b, c;
	double S, L, h,fai,nokori;
	cin >> a >> b >> c;
	
	
	fai = c * 2 * pi / 360;
	h = sin(fai)*b;
	S = a * h / 2;
	nokori = sqrt(a*a + b*b - 2 * a*b*cos(fai));
	L = a + b + nokori;
	cout << fixed << setprecision(5) << S << " " << L << " " << h << endl;

	return 0;

}