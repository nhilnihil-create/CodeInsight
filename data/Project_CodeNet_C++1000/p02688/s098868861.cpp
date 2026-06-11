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
	int n,k,d,a;
	cin>>n>>k;

	vector<bool> mapper(n, false);
	rep(i, 0 , k-1)
	{
		cin>>d;
		rep(j, 0 , d-1){
			cin>>a;
			mapper[a - 1] = true;
		}
	}
	cout<<count(mapper.begin(), mapper.end(), false);
}