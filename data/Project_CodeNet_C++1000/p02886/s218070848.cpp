#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll>pos[21];
ll inp[100];
map<ll,ll>mp;
vector<ll>points;
vector<ll>::iterator upper1, upper2;
int main()
{
  ll i,j,k,l,t,n,x=0,y=0,p,q,z=0;
  cin>>n;
  for(i=0;i<n;i++)
    {
      cin>>p;
      points.push_back(p);	
    }
    for(i=0;i<n;i++)
    {
       for(j=i+1;j<n;j++)
       {
        x=x+points[i]*points[j];	
       }	
    }
    cout<<x;
  
  
     
     
     	
  	
}