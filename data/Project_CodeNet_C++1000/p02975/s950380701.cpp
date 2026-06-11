#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
#define f first
#define s second

int main(){
	ll n ;
	cin>> n ;
	ll sum=0;
	vector<ll> arr(n);
	for(ll i=0 ; i< n ; i++){
		cin>> arr[i];
		sum^=arr[i];
	}
	if(sum)cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
}