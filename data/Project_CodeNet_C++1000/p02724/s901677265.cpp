#include <bits/stdc++.h>
#include<string.h>
#define ll long long 
#include<vector>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int main(){
	IOS;
	ll x;
	cin>>x;
	int ans=0;
	if(x>=500)
	ans+=x/500*1000;
	x%=500;
	if(x>=5)
	ans+=x/5*5;
	cout<<ans;
	
	}