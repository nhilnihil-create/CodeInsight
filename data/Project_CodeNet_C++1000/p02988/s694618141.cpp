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
    string s;
    cin>>n;
    ll arr[n];
    for(i=0;i<n;i++) cin>>arr[i];
    ll count=0;
    for(i=1;i<n-1;i++) 
    {
        if((arr[i-1]<arr[i] && arr[i]<arr[i+1]) || (arr[i-1]>arr[i] && arr[i]>arr[i+1])) 
            count++;
    }
    cout<<count;
}