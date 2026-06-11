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
	ll n,a,b;
	cin>>n>>a>>b;
	
	ll q = n /(a+ b);
	n = n % (a + b);
	if(a >= n)
		cout<<q*a + n;
	else
		cout<<q*a + a;

}