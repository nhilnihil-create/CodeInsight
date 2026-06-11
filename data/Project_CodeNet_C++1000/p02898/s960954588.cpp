#include<bits/stdc++.h>
#define ll long long
#define vl vector
#define pb push_back
#define ff first
#define ss second
using namespace std;

int main()
{
    ll a,b,i,j,n,m,k,t;
    cin>>n>>k;
    ll count=0;
    while(n--)
    {
        cin>>a;
        if(a>=k) count++;
    }
    cout<<count;
}