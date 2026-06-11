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
	int k;
	cin>>k;
	ll sum =0;
	rep(i, 1,k)
		rep(j,1,k)
			rep(l, 1,k)
				sum += gcd(gcd(i,j), l);

	cout<<sum;
}