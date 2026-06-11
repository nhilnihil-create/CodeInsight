#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s,t;
	int n;
	cin>>s>>t;
	n=s.size();
	if(t.substr(0,n)==s)
	cout<<"Yes";
	else
	cout<<"No"; 
	return 0;
}