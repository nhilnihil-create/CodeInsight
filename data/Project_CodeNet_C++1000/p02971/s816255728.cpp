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
    ll a,b,i,j,n,t,c;
    cin>>n;
    vl<ll> arr(n),brr(n);
    for(i=0;i<n;i++) cin>>arr[i];
    brr=arr;
    sort(brr.begin(),brr.end());
    ll flag=0;
    if(brr[n-1]==brr[n-2]) flag=1;
    if(flag==1) for(i=0;i<n;i++) cout<<brr[n-1]<<endl;
    else
    {
        for(i=0;i<n;i++) 
        {
            if(arr[i]==brr[n-1]) cout<<brr[n-2];
            else cout<<brr[n-1];
            cout<<endl;
        }
    }
}