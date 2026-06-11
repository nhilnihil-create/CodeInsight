#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

int n;
int A[1010];
int main(){
	while(cin >> n && n>0){
		double sum = 0;
		double sum2 = 0;
		for(int i=0;i<n;i++){
			cin >> A[i];
			sum += A[i];
			sum2 += A[i]*A[i];
		}
		double sd = sqrt(sum2/n-(sum/n)*(sum/n));
		printf("%.8f\n",sd);
	}
}
