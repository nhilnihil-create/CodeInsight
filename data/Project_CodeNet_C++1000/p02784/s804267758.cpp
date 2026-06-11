#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main(){
	long long n,h,a,sum=0;
	cin>>h>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		sum+=a;
	}
	if(sum>=h){
		cout<<"Yes";
	}
	else{
		cout<<"No";
	}
	return 0;
}