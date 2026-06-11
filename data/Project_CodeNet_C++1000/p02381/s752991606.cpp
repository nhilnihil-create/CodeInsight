#include <string>
#include <cmath>
#include <iostream>
using namespace std;

int main(){
	int n;
	double s[1000];
	double m;
	double a;
	double b;
	while(true) {
		cin >> n;
		if ( n == 0 ) break;
		m=0;
		for (int i = 0 ;i<n ;i++ ) {
			cin >> s[i];
			m+=s[i];
		}
		m = m / n;
		a=0;
		for (int i = 0 ;i<n ;i++ ) {
			b = s[i] - m;
			a += b*b;
		}
		cout << fixed << sqrt( a/n ) << endl;
	}
	return 0;
}