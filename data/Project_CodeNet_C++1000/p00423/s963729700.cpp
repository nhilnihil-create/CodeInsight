#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
	int n;
	int a[10000],b[10000];
	
	while(cin>>n && n!=0){
		int point_a=0;
		int point_b=0;

		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i];
			if(a[i] > b[i]){
				point_a+=(a[i] + b[i]);
			}else if(a[i] == b[i]){
				point_a+=a[i];
				point_b+=b[i];
			}else{
				point_b+=(a[i] + b[i]);
			}
		}
		cout<<point_a<<" "<<point_b<<endl;
	}
	return 0;
}