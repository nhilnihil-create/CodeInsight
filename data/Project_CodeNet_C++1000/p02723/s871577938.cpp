#include<bits/stdc++.h>
#define ll long long

const ll mod = 1000000007 ;

bool isInteger(double n)
{
	if(floor(n)==ceil(n))
		return true ;
	return false ;
}

using namespace std ;

int main()
{
	string s;
	cin>>s;
	if(s[2]==s[3] && s[4]==s[5])
		cout<<"Yes";
	else
		cout<<"No";
}
