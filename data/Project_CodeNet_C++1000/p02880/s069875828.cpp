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
	ll z=0;
	for(ll i=1; i<10; i++){
		for(ll j=1; j<10; j++){
			if(i*j==n){
				z=1;
				break;
			}
		}
	}
	if(z==0)
		cout<<"No";
	else
		cout<<"Yes";
	

}