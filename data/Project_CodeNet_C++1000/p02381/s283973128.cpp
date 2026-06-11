#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
int main(){
	int n;
	while(cin>>n&&n!=0){
		int s[n];
		double m=0;
		for(int i=0;i<n;i++){
			cin>>s[i];
			m+=s[i];
		}
		m/=n;
		double a_2=0;
		for(int i=0;i<n;i++){
			a_2+=(s[i]-m)*(s[i]-m)/n;
		}
		double a=sqrt(a_2);
		cout<<fixed<<setprecision(4)<<a<<endl;
	}
	return 0;
}