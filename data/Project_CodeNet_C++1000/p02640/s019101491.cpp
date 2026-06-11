#include <bits/stdc++.h>
#include <iostream>
typedef long long ll;
#define rep(i,a,b) for(ll i =a ;i <= b;i++)
#define per(i,a,b) for(ll i =a ;i >= b;i--)
using namespace std;


int main(int argc, char const *argv[])
{
	//ifstream cin("input.txt");
	
	int x, y;
	cin>>x>>y;
	
	rep(i,0, x)
	{
		if(i * 2 + (x - i)*4 == y){
			cout<<"Yes";
			return 0;
		}

	}
	cout<<"No";
		



}