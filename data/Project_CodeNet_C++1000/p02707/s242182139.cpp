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
	int n;
	cin>>n;
	vi g(n, 0);

	rep(i, 1, n-1)
	{
		int x;
		cin>>x;
		x--;
		g[x] ++;
	}
	rep(i, 0, n-1)
		cout<<g[i]<<"\n";
}
