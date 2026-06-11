#include<bits/stdc++.h>
using namespace std;
int n,a[10000];
int main(){
	while(true){
		cin>>n;if(n==0)break;for(int i=0;i<n;i++)cin>>a[i];
		sort(a,a+n);int minx=1000000;
		for(int i=0;i<n-1;i++){
			minx=min(minx,a[i+1]-a[i]);
		}
		cout<<minx<<endl;
	}
}