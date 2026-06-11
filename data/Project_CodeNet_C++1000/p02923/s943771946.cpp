#include<bits/stdc++.h>
#define ll long long int 
#define w(x) int x; cin>>x; while(x--)
#define pb push_back
#define mp make_pair
#define mod 1000000007
using namespace std;
int main(){
#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ll n;
	cin>>n;
	ll a[n],mx=0,c=0;
	for(ll i=0; i<n; i++){
		cin>>a[i];
	}
	for(ll i=0; i<n-1; i++){
		if(a[i]>=a[i+1])
			c++;
		else{
			mx=max(mx,c);
			c=0;
		}
	}
	cout<<max(mx,c);
}