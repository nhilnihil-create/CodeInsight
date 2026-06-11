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
    ll a,b,i,j,n,t,c,m=0;
    cin>>n;
    ll arr[n+1],brr[n];
    for(i=0;i<n+1;i++) cin>>arr[i];
    for(i=0;i<n+1;i++) m+=arr[i];
    for(i=0;i<n;i++) cin>>brr[i];
    for(i=0;i<n;i++)
    {
        if(arr[i]>=brr[i])
        {
            arr[i]-=brr[i];
            brr[i]=0;
        }
        else
        {
            brr[i]-=arr[i];
            arr[i]=0;
        }
        if(brr[i]>0)
        {
            if(arr[i+1]>=brr[i])
            {
                arr[i+1]-=brr[i];
                brr[i]=0;
            }
            else
            {
                brr[i]-=arr[i+1];
                arr[i+1]=0;
            }
        }
    }
    for(i=0;i<n;i++) if(brr[i]>0) arr[i+1]-=brr[i];
    ll sum=0;
    for(i=0;i<n+1;i++) if(arr[i]>0) sum+=arr[i];
    cout<<m-sum;
}