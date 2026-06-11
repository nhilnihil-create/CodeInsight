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
	float a,b,c,d;
	cin>>a>>b>>c>>d;
	//cout<<(float)ceil(c/b)<<" "<<ceil(a/d);

	if(ceil(c/b) <= ceil(a/d))
		cout<<"Yes";
	else 
		cout<<"No";
	
}