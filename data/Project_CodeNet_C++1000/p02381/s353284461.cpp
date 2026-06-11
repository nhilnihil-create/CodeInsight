#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int main(){
	double s[1000],n,a,sum=0,b,c=0;
	while (1){
		sum = 0;
		c = 0;
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++){
			cin >> s[i];
			sum += s[i];
		}
		b = sum / n;
		for (int i = 0; i < n; i++){
			c += pow(s[i] - b,2);
		}
		a = sqrt( c / n );
		printf("%f\n", a);

	}

	return 0;
}
