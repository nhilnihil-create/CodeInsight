#include<bits/stdc++.h>
#include<vector>
#include<string>
#include<stack>
#include<iostream>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define vec(a) vector<int>a
using namespace std;
//fibonacci
int binet(int n)
{
	return (pow((1+sqrt(5)),n-1)-pow((1-sqrt(5)),n-1))/(pow(2,n-1)*sqrt(5));
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);
#endif
	fastio
	string str,str1,str2;
	ll n,i,j,k,l,m;
	cin>>n;
	cin>>str1>>str2;
	str="";
	for(i=0;i<n;i++)
	{
		str+=str1[i];
		str+=str2[i];
	}
	cout<<str<<"\n";
	return 0;
}
	