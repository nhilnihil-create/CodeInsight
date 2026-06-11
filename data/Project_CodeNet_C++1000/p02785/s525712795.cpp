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
	ll a,b,z=0;
	cin>>a>>b;
	ll c[a];
	for(ll i=0; i<a; i++)
		cin>>c[i];
	sort(c,c+a);
	for(ll i=a-1-b; i>=0; i--){
		z+=c[i];
	}
	cout<<z;
	

}