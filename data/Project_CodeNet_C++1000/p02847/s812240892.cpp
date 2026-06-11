//#include<bits/stdc++.h>
#include<iostream>
using namespace std;
 
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	string s;
	cin>>s;
	if(s == "SAT") cout<<1;
	if(s == "FRI") cout<<2;
	if(s == "THU") cout<<3;
	if(s == "WED") cout<<4;
	if(s == "TUE") cout<<5;
	if(s == "MON") cout<<6;
	if(s == "SUN") cout<<7;
	
	return 0;
}
