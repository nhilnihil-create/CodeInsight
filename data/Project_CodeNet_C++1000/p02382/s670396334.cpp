#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, x[100], y[100];
	
	cin >> n;
	for(int i=0; i < n; ++i)
		cin >> x[i];
	for(int i=0; i < n; ++i)
		cin >> y[i]; 
		
	for(int p=1; p <= 3; ++p){
		double d=0;
		for(int i=0; i < n; ++i)
			d += pow( fabs(x[i]-y[i]), p);
		
		printf("%f\n", pow(d, 1.0/p));
	}		
	
	double max=0;	
	for(int i=0; i < n; ++i)
		if(max < fabs(x[i]-y[i])) 
		max = fabs(x[i]-y[i]);
	
	printf("%f\n", max);	
	
	return 0;
}

