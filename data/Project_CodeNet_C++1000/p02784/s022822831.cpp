#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int main(){
	int h,n,a,ans=0; 
	cin>>h>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
	    ans=ans+a;
	}
	if(ans>=h){
	cout<<"Yes";}else{
	cout<<"No";}
}