#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<math.h>
#include<cstring>
#include<bits/stdc++.h>
#define ll long long 
using namespace std;
 
int main()
{
	
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll x;
    cin>>x;
    ll n=100;
    ll count=0;
    
    while(n<x)
    {
    	
    	n=n+(n/100);
    	count++;
    	
	}
	

	cout<<count<<endl;
    
    
   return 0;
}
    