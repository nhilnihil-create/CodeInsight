#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;

int main(void){
	//FILE* fp_in = freopen("data.txt", "r", stdin);

	int n;
	while(1){
		cin >> n;
		if( n == 0 ) break;
		vector< int > v;
		double a = 0.0, m = 0.0;
		for(int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			v.push_back( tmp );
			m += ( double )tmp;
		}
		m /= (double) n;
		for(int i = 0; i < n; i++)
			a += ( v[i] - m ) * ( v[i] - m );
		a /= (double) n;
		a = sqrt( a );
		printf("%.5lf\n",a);
	}
	//while(1){}
	return 0;
}