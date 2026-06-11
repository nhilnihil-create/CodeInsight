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
    ll a,b,i,j,n,t;
    cin>>n;
    ll arr[n],brr[n],crr[n-1];
    for(i=0;i<n;i++) cin>>arr[i];
    for(i=0;i<n;i++) cin>>brr[i];
    for(i=0;i<n-1;i++) cin>>crr[i];
    ll sat=0;
    for(i=0;i<n;i++)
    {
        if(i==0) sat+=brr[arr[i]-1];
        else if(arr[i]==arr[i-1]+1) 
        {
            sat+=crr[arr[i]-2];
            sat+=brr[arr[i]-1];
        }
        else sat+=brr[arr[i]-1];
    }
    cout<<sat;
}