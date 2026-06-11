#include<bits/stdc++.h>
using namespace std;
int main(){
	long long a[3]={},b[3]={};
	int n=2,m=2;
	for(int i=0;i<2;i++){
		scanf("%lld",&a[i]);
		
	}
	if(a[0]<=0&&a[1]>=0)n=3;
	for(int i=0;i<2;i++){
		scanf("%lld",&b[i]);
	}
	if(b[0]<=0&&b[1]>=0)m=3;
	long long res;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i==0&j==0||res<a[i]*b[j]){
				res=a[i]*b[j];
			}
		}
	}
	cout<<res;
	
}