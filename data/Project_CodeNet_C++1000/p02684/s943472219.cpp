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
	ll n, k,A;
	cin>>n>>k;
	vi graph(n);
	rep(i,0,n-1)
	{
		cin>>A;
		A--;
		graph[i] = A;
	}
	
	vi ordering(n, -1);
	int count = 1;
	int start = 0;
	int prev;
	while(ordering[start] == -1)
	{
		ordering[start] = count;
		count++;
		prev = start;
		start = graph[start];
	}
	ll z = ordering[prev] - ordering[start] + 1;

	if(k > ordering[start] - ordering[0])
		z = (k - (ordering[start] - ordering[0])) % z;
	else{
			z = k;
			start = 0;
	}
	rep(i, 1, z)
		start = graph[start];
	cout<<start +1;

}