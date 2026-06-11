#include<iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main() {
	int n, s[1000], i;
	double a,m;
	while (cin >> n, n){
		m = 0;
		for (i = 0; i<n; i++){
			cin >> s[i];
			m += s[i];
		}
		m /= n;
		a = 0;
		for (i = 0; i<n; i++){
			a += pow(s[i] - m, 2);
		}
		a /= n;
		printf("%.8f\n", sqrt(a));

	}
}