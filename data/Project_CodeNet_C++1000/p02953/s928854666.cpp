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
    vl<ll> arr(n);
    for(i=0;i<n;i++) cin>>arr[i];
    for(i=n-1;i>0;i--) if(arr[i-1]>arr[i]) arr[i-1]--;
    for(i=0;i<n-1;i++)
    {
        if(arr[i]>arr[i+1])
        {
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
    return 0;
}