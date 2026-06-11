#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	if(400<=t&&t<=599)cout<<8;
	else
	if(600<=t&&t<=799)cout<<7;
	else
	if(800<=t&&t<=999)cout<<6;
	else
	if(1000<=t&&t<=1199)cout<<5;
	else
	if(1200<=t&&t<=1399)cout<<4;
	else
	if(1400<=t&&t<=1599)cout<<3;
	else
	if(1600<=t&&t<=1799)cout<<2;
	else
	cout<<1;
	return 0;
}