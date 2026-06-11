
                                 /*Bismillahir Rahmanir Rahim*/


#include<bits/stdc++.h>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define ll long long int
#define dd double
using namespace std;

int main()
{
 ll a,b;
 cin>>a>>b;
 if(a==1)
 cout<<b<<endl;
 else
 {
    ll x=a-1;
   
    for(ll i=x;i>=0;i--)
    {
       cout<<b-i<<" ";
    }
    for(ll i=1;i<=x;i++)
    {
       cout<<b+i<<" ";
    }
 }
 
}
