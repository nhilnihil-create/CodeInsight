#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<stack>
#include<iostream>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define MOD 1000000007
#define vec(a) vector<int>a
using namespace std;



int main()
{
#ifndef ONLINE_JUDGE
	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);
#endif
		ll n,i,j,l,k;
		cin>>n;
		l=n%10;
		if(l==0 || l==1 || l==6 || l==8)
			cout<<"pon"<<"\n";
		else if(l==3)
			cout<<"bon"<<"\n";
		else 
			cout<<"hon\n";
		return 0;
}
	
