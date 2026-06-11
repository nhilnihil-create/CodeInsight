#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

int main()
{
	fastio;
	string s;
	cin>>s;
	if(s=="SUN")
		cout<<7;
	if(s=="MON")
		cout<<6;
	if(s=="TUE")
		cout<<5;
	if(s=="WED")
		cout<<4;
	if(s=="THU")
		cout<<3;
	if(s=="FRI")
		cout<<2;
	if(s=="SAT")
		cout<<1;
	return 0;
}
