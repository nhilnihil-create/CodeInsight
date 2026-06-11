#include<bits/stdc++.h>
#define ll long long 
#define ld long double
#define vl vector
#define pb push_back
#define ff first
#define ss second
using namespace std;

int main()
{
    ll n,m,i,a=0,b=0,k,t,j;
    cin>>n;
    ll arr[n];
    for(i=0;i<n;i++) cin>>arr[i];
    ll count=1;
    ll brk=0;
    for(i=0;i<n;i++)
    {
        if(count==arr[i]) count++;
        else brk++;
    }
    if(brk==n) cout<<"-1";
    else cout<<brk;
}