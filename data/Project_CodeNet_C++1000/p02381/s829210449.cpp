#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

int main(){
	double n,s[100000];
	double m,a;
	while(cin>>n){
		if(n==0)break;
		m=0;
		a=0;
		for(int i=0;i<n;i++){
			cin>>s[i];
			m+=s[i];
		}
		m=m/n;
		for(int i=0;i<n;i++){
			a+=((s[i]-m)*(s[i]-m)/n);
		}
		cout<<fixed<<setprecision(5)<<sqrt(a)<<endl;
	}
}
