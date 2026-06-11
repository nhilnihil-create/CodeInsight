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
    ll a,b,i,j,n,t,l;
    string s;
    cin>>n>>l;
    ll arr[n];
    for(i=0;i<n;i++) arr[i]=l+(i+1)-1;
    ll mn=INT_MAX,val;
    for(i=0;i<n;i++)
    {
        if(abs(arr[i])<mn)
        {
            mn=abs(arr[i]);
            val=arr[i];
        }
    }
    ll sum=0;
    for(i=0;i<n;i++) sum+=arr[i];
    sum-=val;
    cout<<sum;
    
}