#include<bits/stdc++.h>
#include<vector>
#include<cmath>
#include<string>
#include<sstream>
#include<iostream>
#define ll long long 
#define ld long double
#define rep(i,n) for(i=0;i<n;i++)
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL) 
using namespace std;
int main()
{
	fastio;
	int a,b;
    cin>>a>>b;
    if (b>=a)
        cout<<"0"<<endl;
    else
    {
        if (a-2*b>0)
            cout<<a-2*b<<endl;
        else 
            cout<<"0"<<endl;
    }	
}