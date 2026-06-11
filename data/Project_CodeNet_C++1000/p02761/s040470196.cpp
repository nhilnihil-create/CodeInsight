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
	
	int n, m,si,ci;
	cin>>n>>m;
	unordered_map <int,int> num;
	rep(i,0,m-1)
	{
		cin>>si>>ci;
		if(num.find(si) != num.end() && num[si] != ci)
		{
			cout<<-1;
			return 0;
		}
		else
			num[si] = ci;
	}
	int d1,d2,d3;
	if(n == 3)
	{
		if(num.find(1) == num.end())
			cout<<1;
		else if(num[1] == 0){
				cout<<-1;
				return 0;
			}
			else
			{
				cout<<num[1];
			}

		if(num.find(2) == num.end())
			cout<<0;
		else
			cout<<num[2];

		if(num.find(3) == num.end())
			cout<<0;
		else
			cout<<num[3];


	}else if(n == 2)
	{

			if(num.find(1) == num.end())
				cout<<1;
			else if(num[1] == 0)
			{
				cout<<-1;
				return 0;
			}
			else
				cout<<num[1];

			if(num.find(2) == num.end())
				cout<<0;
			else
				cout<<num[2];
	}
	else
	{

			if(num.find(1) == num.end())
				cout<<0;
			else
				cout<<num[1];
	}
}