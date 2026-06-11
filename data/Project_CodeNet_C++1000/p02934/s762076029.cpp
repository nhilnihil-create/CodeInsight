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
    ld ans=0;
    ld x;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x;
        ans+=1/x;
    }
    ans=1/ans;
    cout<<setprecision(8)<<fixed<<ans;
}