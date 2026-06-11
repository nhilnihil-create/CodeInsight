#include <bits/stdc++.h>
#include <iostream>
typedef long long ll;
#define rep(i,a,b) for(ll i =a ;i <= b;i++)
#define per(i,a,b) for(ll i =a ;i >= b;i--)
using namespace std;


int main(int argc, char const *argv[])
{
	//ifstream cin("input.txt");
	ll n;
	double b;
	cin>>n>>b;
	ll  c = (b*100 + .5);
	ll res = n*c;
	res = res/100;
	cout<<res;
	//cout<<(ll)floor((n * (b * 100))/100);
	

}