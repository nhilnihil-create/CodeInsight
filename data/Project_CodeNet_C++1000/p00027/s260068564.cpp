#include<iostream>
using namespace std;
main(){
	int month[12]={31,29,31,30,31,30,31,31,30,31,30,31};
	string day[7]={"Wednesday","Thursday","Friday","Saturday","Sunday","Monday","Tuesday"};
	int n[2];
	while(cin>>n[0]>>n[1],n[0],n[1]){
		int sum=0;
		for(int i=0;i<n[0]-1;++i){
			sum+=month[i];
		}
		sum+=n[1];
		cout<<day[sum%7]<<endl;
	}
}