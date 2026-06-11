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
	int n,m;
	cin>>n>>m;
	ll sum =0;
	ll x;
	rep(i, 0 ,m-1)
	{
		cin>>x;
		sum += x;
	}
	if(sum > n)
		cout<<-1;
	else
		cout<<n-sum;
	
}