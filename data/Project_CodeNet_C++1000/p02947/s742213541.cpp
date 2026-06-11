#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<stack>
#include<iostream>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define vec(a) vector<int>a
using namespace std;


int main()
{
#ifndef ONLINE_JUDGE
	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);
#endif
	fastio
	ll n,i,j,k,l,m,z;
	cin>>n;
	vector<string> vec;
	for(i=0;i<n;i++)
	{
		string str;
		cin>>str;
		sort(str.begin(),str.end());
		vec.push_back(str);
	}
	sort(vec.begin(),vec.end());
	z=0;
	k=0;
	l=0;
	for(i=0;i<vec.size()-1;i++)
	{
		if(vec[i]==vec[i+1])
		{
			z++;
			l++;
		}
		else
		{
			k+=z*(z+1)/2;
			z=0;
			l=0;
		}
		if(i==vec.size()-2 && l!=0)
		{
			k+=z*(z+1)/2;
		}
	}
	cout<<k<<"\n";
	return 0;
}
