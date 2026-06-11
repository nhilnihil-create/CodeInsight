#include<bits/stdc++.h>
using namespace std;

int main(){
	double a, b;
	cin >> a >> b;
	b *= 100;
	b += 0.00001;

	long long x, y;
	x = a;
	y = b;
	cout << (x*y)/100 << endl;
}