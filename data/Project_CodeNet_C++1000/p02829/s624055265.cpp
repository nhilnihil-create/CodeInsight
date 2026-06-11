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
	ll a,b;
	cin>>a>>b;
	if(a==1 && b==2)
		cout<<3;
	if(a==1 && b==3)
		cout<<2;
	if(a==2 && b==3)
		cout<<1;
	if(a==2 && b==1)
		cout<<3;
	if(a==3 && b==1)
		cout<<2;
	if(a==3 && b==2)
		cout<<1;
}