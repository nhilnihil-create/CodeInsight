#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
	ll x,y;
	cin>>x>>y;
	if(y%2!=0){
		cout<<"No"; 
		return 0;
	}

	ll t = y/2 - x;
	ll c = x-t;
	if(t>=0 && c>=0){
		cout<<"Yes";
	}
	else{
		cout<<"No";
	}
}