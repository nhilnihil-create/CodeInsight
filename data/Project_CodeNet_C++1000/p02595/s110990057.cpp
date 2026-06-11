#include<bits/stdc++.h> 
#define ll long long 
#define pb push_back 
#define vec vector<int> 
#define fo(i,n) for (ll i = 0; i < n; i++)
#define so(v) sort(v.begin(), v.end())
#define fi first
#define se second 
using namespace std;  
int main()
{
 ll n,d;
cin>>n>>d;
int count=0;
ll x,y;
fo(i,n)
{
    cin>>x>>y;
    if((x*x+y*y)<=d*d)
       
    {
        count++;
    }
}
cout<<count;

}