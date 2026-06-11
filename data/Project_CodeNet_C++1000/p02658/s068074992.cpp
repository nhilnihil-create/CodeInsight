#include <bits/stdc++.h>
#include <iostream>
typedef long long ll;
#define rep(i,a,b) for(ll i =a ;i <= b;i++)
#define per(i,a,b) for(ll i =a ;i >= b;i--)
using namespace std;


int main(int argc, char const *argv[])
{
	//ifstream cin("input.txt");
	int n;
	cin>>n;
	ll ans = 1, in,flag = 0;
	const ll t = 1e18;

	rep(i,0,n-1){
		cin>>in;		
		if(in == 0){
			cout<<0;
			return 0;
		}
		if(in <= 1000000000000000000/ans)
			ans *= in;
		else
		{
			flag = 1;
		}
	}
	if(flag)
		cout<<"-1";
	else
		cout<<ans;
	

}