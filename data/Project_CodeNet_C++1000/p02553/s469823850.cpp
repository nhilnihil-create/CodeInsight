#include<stdio.h>
#include<iostream>
#include<algorithm> 
using namespace std;
typedef long long ll;

int main(){
	ll s1[10];
	for(int i=1;i<=4;i++)	cin>>s1[i];
	ll s=s1[1]*s1[3];
	for(int i=1;i<=2;i++){
		for(int j=3;j<=4;j++){
			s=max(s,s1[i]*s1[j]);
		} 
	}
	cout<<s<<endl;
	return 0;
} 