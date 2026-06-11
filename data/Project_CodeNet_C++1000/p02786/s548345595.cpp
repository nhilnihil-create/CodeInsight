#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifndef ONLINE_JUDGE
	//freopen("input.txt","r",stdin);
#endif

	ll n;
	cin>>n;
	ll temp=log2(n);
	ll a=powl(2,temp+1)-1;
	cout<<a<<endl;
	return 0;
}