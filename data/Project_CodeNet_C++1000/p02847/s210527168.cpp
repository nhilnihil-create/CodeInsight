#include<bits/stdc++.h>
using namespace std;
#define nl '\n' 
#define fast ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define pii pair <int,int>
ll mod=1000000007;
int main()
{
	fast;
	map<string,int>m;
	m["SAT"]=1;
	m["SUN"]=7;
	m["MON"]=6;
	m["TUE"]=5;
	m["WED"]=4;
	m["THU"]=3;
	m["FRI"]=2;
	string s;cin>>s;
	cout<<m[s];
}