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
	ll c[b];
	for(ll i=0; i<b; i++)
		cin>>c[i];
	sort(c,c+b);
	for(ll i=b-1; i>=0; i--){
		a-=c[i];
		if(a<=0){
			z=1;
			break;
		}
	}
	if(z==1)
		cout<<"Yes";
	else
		cout<<"No";

}