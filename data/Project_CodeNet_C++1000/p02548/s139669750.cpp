#include <bits/stdc++.h>
#define ll long long
#define pb push_back
ll mod=1000000007;
using namespace std;


int main(){
	ll n;
	cin>>n;
	ll c=0;
	for(ll i=1;i<n;i++){
		for(ll j=1;j<n;j++){
			if(i*j<n){
				c++;
			}else{
				break;
			}
		}
	}

	cout<<c<<endl;
}