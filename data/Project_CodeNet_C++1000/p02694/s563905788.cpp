#include <bits/stdc++.h>
#include <iostream>
typedef long long ll;
#define rep(i,a,b) for(ll i =a ;i <= b;i++)
#define per(i,a,b) for(ll i =a ;i >= b;i--)
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;


int main(int argc, char const *argv[])
{
	//ifstream cin("input.txt");
	ll x;
	cin>>x;
	ll bal = 100;
	ll count = 0;
	while(x > bal)
	{
		bal += bal/100;
		count ++; 
	}
	cout<<count;

}