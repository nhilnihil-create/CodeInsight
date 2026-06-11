//xotwod
#include<bits/stdc++.h>
using namespace std; 
#define gol(n) for(ll u=0;u<n;u++)
typedef long long ll;
int main(){
	int k,a,b,f=0;cin>>k>>a>>b;
	for(int u=a;u<=b;u++){
		if(u%k==0) f=1;}
	cout<<(f? "OK":"NG");
}
