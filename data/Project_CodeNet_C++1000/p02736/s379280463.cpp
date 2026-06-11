#include <bits/stdc++.h>
#define rep(i,n) for((i)=1;(i)<=(n);(i)++) 
using namespace std;
int n,i,j,a[1000005],b[1000005],s,c1;
int c(int x,int y){
	if(x<y) return 0;
	if(x<=1&&y<=1) return 1;
	return c(x/2,y/2)*c(x%2,y%2);
}
int main(){
	scanf("%d ",&n); 
	rep(i,n){
		char c;
		scanf("%c",&c);
		a[i]=c-48;
	}
	if(n==1){
		cout<<a[1]<<endl;
		return 0;
	}
	rep(i,n-1){
		b[i]=abs(a[i+1]-a[i]);
		if(b[i]==1) c1=1;
	}
	if(c1){
		rep(i,n-1){
			if(c(n-2,i-1)) s^=(b[i]&1);
		}
	}
	else{
		rep(i,n-1){
			if(c(n-2,i-1)) s^=b[i];
		}
	}
	cout<<s<<endl;
	return 0;
}