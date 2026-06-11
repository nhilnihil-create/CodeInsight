#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>
#define PI 3.1415926535897932
using namespace std;

int main(){
	int n,s[1000];
	double mean;
	while(cin >> n,n){
		double sum=0;
		for(int i=0;i<n;i++){
			cin >>s[i];
			sum+=s[i];
		}
		mean=sum/(double)n;
		sum=0;
		for(int i=0;i<n;i++){
			sum+=(double)((double)s[i]-mean)*((double)s[i]-mean);
		}
		printf("%.6f\n",sqrt((double)sum/n));
	}
	return 0;
}