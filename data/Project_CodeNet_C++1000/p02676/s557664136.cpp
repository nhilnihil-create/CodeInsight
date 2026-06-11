#include <bits/stdc++.h>
#include <iostream>
typedef long long ll;
#define rep(i,a,b) for(ll i =a ;i <= b;i++)
#define per(i,a,b) for(ll i =a ;i >= b;i--)
using namespace std;


int main(int argc, char const *argv[])
{
	//ifstream cin("input.txt");
	int k;
	string s;
	cin>>k;
	cin>>s;
	if(k >= s.length())
		cout<<s;
	else
	{
		s = string(s.begin(), s.begin() + k);
	cout<<s<<"...";
	}

}