#include <bits/stdc++.h>
#include <iostream>
typedef long long ll;
#define rep(i,a,b) for(ll i =a ;i <= b;i++)
#define per(i,a,b) for(ll i =a ;i >= b;i--)
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int gcd(int a, int b)
{
	if(a == 0)
		return b;

	return gcd(b % a, a);
}

int main(int argc, char const *argv[])
{
	//ifstream cin("input.txt");
	ll n,k;
	cin>>n>>k;
	
	n = n%k;
	cout<<min(n, abs(n-k));
}