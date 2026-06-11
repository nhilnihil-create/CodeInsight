#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main(){
	while(1){
		
		int n;
		double m = 0,a1 = 0,a2 = 0;
		
		cin >> n;
		if(n == 0) break;
		double *s = new double [n];
		for(int i = 0;i < n;i++){
		s[i] = 0;
		}
		for(int i = 0;i < n;i++){
			cin >> s[i];
		}
		
		for(int i = 0;i < n;i++){
			m += s[i];
		}
		m = m / n;
		for(int i = 0;i < n;i++){
			a2 += pow(s[i] - m,2);
		}
		a1 = sqrt(a2 / n);
		delete[] s;
		printf("%f\n",a1);
	}
	return 0;
}