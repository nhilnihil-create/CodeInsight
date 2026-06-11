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
	string s,t;
	cin>>s>>t;
	ll c=0;
	for(ll i=0; i<3; i++){
		if(s[i]==t[i])
			c++;
	}
	cout<<c;
}