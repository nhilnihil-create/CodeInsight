// Starting with the name of Allah

#include <bits/stdc++.h>
#define ll long long
#define nl endl
#define Nayon ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define gcd(a,b)         __gcd(a,b)
#define lcm(a,b)         (a/gcd(a,b))*b


using namespace std;



int main()
{
	Nayon;
	int a,b,i,n;
	cin>>n;
	if(n>=400 && n<=599){
		cout<<8;
	}
	else if(n>=600 && n<=799){
		cout<<7;
	}
	else if(n>=800 && n<=999){
		cout<<6;
	}
	else if(n>=1000 && n<=1199){
		cout<<5;
	}
	else if(n>=1200 && n<=1399){
		cout<<4;
	}
	else if(n>=1400 && n<=1599){
		cout<<3;
	}
	else if(n>=1600 && n<=1799){
		cout<<2;
	}
	else if(n>=1800 & n<=1999){
		cout<<1;
	}
	return 0;
}
