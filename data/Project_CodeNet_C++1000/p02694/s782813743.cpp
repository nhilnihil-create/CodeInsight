#include<bits/stdc++.h>
#define ll long long int
#define l(i,a,b) for(ll i=a;i<b;i++)
using namespace std;
int main(){
	ll x,count=0,a=100;
	ll calc =0;
	cin>>x;
	while(a<x){
		calc = a/100;
		a+=calc;
		count++;
	}
	cout<<count<<"\n";
}
