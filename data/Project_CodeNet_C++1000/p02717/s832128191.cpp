#include<iostream>
#include<stdio.h>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<math.h>
#include<cstring>
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
int main()
{
	
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
     int x,y,z;
     cin>>x>>y>>z;
     
     swap(x,y);
     swap(x,z);
     
     cout<<x<<" "<<y<<" "<<z<<endl;
     
 
 
    
    return 0;
    
}