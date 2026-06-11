#include<iostream>
using namespace std;
int main(){
	int a[31],n;
	a[1]=1;
	a[0]=1;
	a[2]=2;
	for(int i=3;i<=30;i++){
		a[i]=a[i-1]+a[i-2]+a[i-3];
	}
	while(cin>>n,n){
		if(a[n]%3650==0)
		cout<<a[n]/3650<<endl;
		else
		cout<<a[n]/3650+1<<endl;
	}
	return 0;
}