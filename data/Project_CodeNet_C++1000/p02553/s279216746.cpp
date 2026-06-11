#include<iostream>
#include <cstdio>
#include <cmath>
#include <cstring> 
#include <algorithm>
using namespace std;
#include <queue> 
#define ll long long
int main()
{
	ll a,b,c,d;
	ll x,y;
	cin>>a>>b>>c>>d;
	x=(a*c>=b*d?a*c:b*d);
	y=(b*c>=a*d?b*c:a*d);
//	cout<<x<<endl<<y<<endl;
	cout<<(x>=y?x:y);
}