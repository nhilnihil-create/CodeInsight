#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#define PI 3.1415926535
using namespace std;

int main(void){
	double a2, avg;
	int n, s[1001]={0}, sum;
	while(1){
		sum=0;
		a2=0.0;
		cin >>n;
		if(n==0){
			break;
		}
		for(int i=0; i<n; i++){
			cin >>s[i];
			sum+=s[i];
		}
		avg=(double)sum/n;
		for(int i=0; i<n; i++){
			a2+=pow(s[i]-avg, 2);
		}
		a2=sqrt(a2/n);
		cout <<fixed <<setprecision(10) <<a2 <<endl;
	}
    return 0;
}