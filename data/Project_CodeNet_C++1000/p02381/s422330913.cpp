#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;

int main(){
	
	double m,D,a2;
	
	int n;
	while(1){
		cin >> n;
		if (n==0) break;
		int s[n];
		m=0, a2=0, D=0;
		for (int i=0; i<n; i++){
			cin >> s[i] ;
			m+=s[i];
		}
		m/=n;
		for (int i=0; i<n; i++){
			a2+=pow(s[i]-m, 2);
		}
		a2/=n;
		D=sqrt(a2);
		printf("%.8f\n", D);
	}
	return 0;
}