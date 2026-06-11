#include<iostream>
#include<vector>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;

int main(){
	long long int x;
	cin>>x;
	long long int a = 100;
	int cnt=0;
	while(a<x){
		cnt++;
		a=a+a/100;
	}
	cout<<cnt<<endl;

	return 0;
}