#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int n;
	int dt[300000];
	for(int i=0;i<300000;i++){
		dt[i]=1;
	}
	dt[0]=dt[1]=0;
	for(int i=2;i<sqrt(300000);i++){
		for(int j=(i*2);j<300000;j+=i){
			dt[j]=0;
		}
	}
	while(1){
		cin>>n;
		if(n==0)break;
		int cnt=0;
		for(int i=n+1;i<=2*n;i++){
			if(dt[i]==1){
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}