#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
	int  n;
	long double ave;    //??????
	long double sum1=0;  //????¨????
	long double sum2=0;
	int s[1000]={0};     //??????
	long double a;   //?????£
	
	while(1){
		cin>>n;
		if(n==0)
			break;
		for(int i=0;i<n;i++){
			cin>>s[i];
			sum1+=s[i];
		}
		ave=sum1/n;
		for(int i=0;i<n;i++)
			sum2+=(s[i]-ave)*(s[i]-ave);
		
		a=sum2/n;
		cout<<fixed<<setprecision(6)<<sqrt(a)<<endl;
		sum1=0;
		sum2=0;
		ave=0;
	}
}
	
	
	