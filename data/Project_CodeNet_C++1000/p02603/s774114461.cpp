#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<queue>
#include<cmath>
#include<math.h>
using namespace std;
int main(){
	long int n,a[205],p=0,k=0,s=1000;
	cin>>n;
	for(long int i=0;i<n;i++)cin>>a[i];
	for(long int i=0;i<n-1;i++){
		if(a[i]<=a[i+1]){
			k=k+s/a[i];
			s=s-s/a[i]*a[i];
		}
		if(a[i]>a[i+1]){
			s=s+k*a[i];
			k=0;
		}
	}
	s=s+k*a[n-1];
	cout<<s;
	
    
    return 0;
}
