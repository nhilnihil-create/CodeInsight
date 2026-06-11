#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int main(){
	int n;
	while(cin>>n&&n!=0){
		double s[1000]={0.0},ave=0.0,sum=0.0;
		for(int i=0;i<n;i++){
			cin>>s[i];
			ave+=s[i];
		}
		ave=ave/n;
		for(int i=0;i<n;i++){
			s[i]=pow((s[i]-ave),2);
			sum+=s[i];
		}
		printf("%.8lf\n",sqrt(sum/n));
	}
	return 0;
}