#include<bits/stdc++.h>
#define ll long long 
#define ld long double
#define pb push_back
#define vl vector
#define ff first
#define ss second
using namespace std;
int main()
{
    ll a,b,i,j,n,t;
    cin>>n;
    string s;
    ll count=0;
    for(i=1;i<=n;i++)
    {
        s=to_string(i);
        if(s.size()%2) count++;
    }
    cout<<count;
    
}