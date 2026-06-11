#include<iostream>
using namespace std;
int main(){

	int x,i,num[100];
	cin>>x;

	for( i=0;i<x;i++){
		cin>>num[i];
	}
	for(i=x-1;i>0;i--){
		cout<<num[i]<<' ';
	}
	cout<<num[0]<<endl;
	return 0;
}