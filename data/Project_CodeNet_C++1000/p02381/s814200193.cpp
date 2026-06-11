#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int main(){
	double m;
	double sd,sd2;
	int point[1000];
	int n,sum;
	while(1){
		sum = 0;
		sd2 = 0;
		cin >>n;
		if(n==0){break;}
		for(int i=0 ; i<n ;i++){
			cin >> point[i];
			sum +=point[i];
		}
		m = (double)sum/(double)n;
		for(int i=0; i<n ;i++){
			sd2 +=pow((point[i]-m),2); 
		}
		sd = sqrt((sd2)/(double)n);
	
	 printf("%.9f\n",sd);
	}
	return 0;
}