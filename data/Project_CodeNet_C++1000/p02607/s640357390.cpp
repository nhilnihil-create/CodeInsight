#include<iostream>
#include<stdio.h>
#include<cmath> 
#include<stack> 
#include<algorithm> 
#include <string.h>
using namespace std;
int main() {
	int l,r,d,s=0,n,m;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m;
		if(m%2==1&&i%2==1) s++;
	}
	cout<<s<<endl;
	return 0;
}