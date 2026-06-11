#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

int main() {
	int n;
	double s[1005];
	while(cin>>n && n!=0){
		double sum=0;
		for(int i=0;i<n;i++){
			cin>>s[i];
			sum +=s[i];
		}
		double avg=sum/n;
		sum=0;
		for(int i=0;i<n;i++){
			sum+=(s[i]-avg)*(s[i]-avg);
		}	
		if(sum==0){
			printf("%lf\n",sum);
		}else{
			printf("%lf\n",sqrt(sum/n));
		}

	}
	return 0;
}