#include<bits/stdc++.h>
#define ll long long

const ll mod = 1000000007 ;

using namespace std ;

int main()
{
	int n,x,t ;
	cin>>n>>x>>t;
	int y = ceil((double)n/x);
	cout<<y*t;
}
