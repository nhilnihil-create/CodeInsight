#include<bits/stdc++.h>
using namespace std;
void out(int a,int b){
	cout<<a<<" "<<b<<endl;
}
int main(){
	int n;cin>>n;
	int s;
	for(int i=1;i<20;i++){
		if((1<<i)-1>n){
			break;
		}
		s=(1<<i)-1;
	}
	if(n==s+1||n==1){
		cout<<"No"<<endl;
		return 0;
	}
	cout<<"Yes"<<endl;
	for(int i=1;i<s;i++){
		out(i,i+1);
	}
	out(s,n+1);
	for(int i=n+1;i<n+s;i++){
		out(i,i+1);
	}
	if(n>=s+2){
		out(1,s+1);
		out(s+1,s+2);
		out(1,s+2+n);
		out(s+2+n,s+1+n);
	}
	for(int i=s+3;i<=n;i++){
		out(i-1+n,i);
		out(i-s-1,i+n);
	}
}
