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
	for(ll i=1; i<=n; i++){
		if(i*108/100==n){
			cout<<i;
			return 0;
		}
	}
	cout<<":(";
		
}