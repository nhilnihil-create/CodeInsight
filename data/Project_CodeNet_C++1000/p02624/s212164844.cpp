#include <bits/stdc++.h>
#include <iostream>
typedef long long ll;
#define rep(i,a,b) for(ll i =a ;i <= b;i++)
#define per(i,a,b) for(ll i =a ;i >= b;i--)
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

ll count_divs[10000000] = {0};
void solve(int n)
{
	//fill(count_divs + 1, count_divs+n+1, 0);
	rep(i, 1, n)
		for(ll j = i ; j <= n; j+=i)
			count_divs[j] += 1;
}



int main()
{
	//ifstream cin("input.txt");
	int n;
	cin>>n;
	ll sum = 0;
	solve(n);
	rep(i, 1, n)
	{
		sum += i * count_divs[i];
	}
	cout<<sum;
}