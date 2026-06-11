#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int gcd(int a,int b){
	if(a==0)
	return b;
	if(b==0)
	return a;
	if(a==b)
	return a;
	if(a>b)
	return gcd(a-b,b);
	return gcd(a,b-a);
}

int GCD(int a,int b){
	if(a==0)
	return b;
	if(b==0)
	return a;
	if(a==b)
	return a;
	return GCD(b,a%b);
}

int main(){
	ll a,b;
	cin>>a>>b;
	if((a+b)%2==0){
		cout<<(a+b)/2<<endl;
		
	}
	else
	cout<<"IMPOSSIBLE"<<endl;
}