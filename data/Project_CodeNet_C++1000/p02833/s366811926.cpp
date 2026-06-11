#include<bits/stdc++.h>
//#include<iostream>
using namespace std;
 
typedef long long ll;
const int N = 200005;

 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	ll n;
	cin>>n;
	
	ll ans = 0;
	ll x = 10;
	if(n%2 == 0){
		while(x <= n){
			ans += n/x;
			x *= 5;
		}	
	
		cout<<ans;
	}
	else{
		cout<<0;
	}
	return 0;
}
