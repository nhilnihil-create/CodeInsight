#include <bits/stdc++.h>
#include <iostream>
typedef long long ll;
#define rep(i,a,b) for(ll i =a ;i <= b;i++)
#define per(i,a,b) for(ll i =a ;i >= b;i--)
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;




int main()
{
	//ifstream cin("input.txt");
	ll n,k;
	cin>>n>>k;
	ll hi = k;
	int count = 1;
	while(n >= hi)
	{
		hi *=k;
		count ++;
	}
	cout<<count;
}