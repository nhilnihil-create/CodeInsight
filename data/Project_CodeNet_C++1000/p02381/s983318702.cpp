#include <iostream>
#include <cmath>
#include <stdio.h>

using namespace std;

int main(){
	int n,m;
	int a[1000];
	int sum;
	double large_sum ;
	double stdev[1000];
	
	for (int j = 0; j < 1000; j++){
		sum = 0;
		large_sum = 0;
		cin >> n;
		if (!n) { m = j; break; }
		for (int i=0; i<n; i++){
			cin >> a[i];
			sum += a[i];
		}
		double avg = (double)sum / n;
		
		for (int i=0; i<n; i++){
			large_sum += (a[i] - avg) *  (a[i] - avg);	
		}
		
		stdev[j] = sqrt(large_sum / n);
	}
	for (int i=0; i<m; i++){	
		printf("%.8lf\n", stdev[i]);
	}
	return 0;
}