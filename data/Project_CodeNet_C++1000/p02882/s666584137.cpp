#include<bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
//g++ -std=c++11 

#define PI 3.14159265359

using namespace std;

long long a, b, x;


int main(){
	cin >> a >> b >> x;

	double start = 0;
	double end = PI/2;

	while(start + 0.000000001 < end) {
		double sita = (start + end)/2;
		double l = b * tan(PI/2 - sita);
		double vol;

		if(l > a) {
			double l2 = a / tan(PI/2 - sita);
			vol = ((l2 * a /2.0) + a * (b - l2)) * a;
		} else {
			vol = a * l * b / 2.0;
		}

		if(vol > x) {
			start = sita;
		} else {
			end = sita;
		}
	}

	printf("%.10f\n", 180 * start / PI);

}
