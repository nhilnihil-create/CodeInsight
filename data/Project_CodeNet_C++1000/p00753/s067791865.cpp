#include<iostream>
#include<cmath>
using namespace std;
bool pr[300000]={0};
bool is_sosu(int a){
	for(int i=2;i<=sqrt(a);i++){
		if(a%i==0)return false;
	}
	return true;
}
int main(){
	for(int i=2;i<=300000;i++){
		pr[i]=is_sosu(i);
	}
	int n;
	while(cin>>n,n){
		int cnt=0;
		for(int i=n+1;i<=2*n;i++){
			if(pr[i]){
			//cout<<i<<endl;
			cnt++;
			}
		}
		cout<<cnt<<endl;
	}
}