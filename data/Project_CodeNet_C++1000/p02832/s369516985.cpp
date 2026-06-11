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
	ll a[n];
	ll c=0,z=1,v=0;
	for(ll i=0; i<n; i++){
		cin>>a[i];
		if(a[i]==z){
			v=1;
			z++;
		}
		else
			c++;
	}
	if(v==1)
		cout<<c;
	else
		cout<<-1;

}