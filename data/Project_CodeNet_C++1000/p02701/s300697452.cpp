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
	string s;
	unordered_map <string, bool>cnt;

	int n;
	cin>>n;
	rep(i, 0, n-1)
	{
		cin>>s;
		cnt[s] = true;
	}
	cout<<cnt.size();
	
	
}