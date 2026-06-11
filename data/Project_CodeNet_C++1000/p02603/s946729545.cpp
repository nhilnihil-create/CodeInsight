#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void code()
{
    ll n;
    cin>>n;
    ll A[n];
    for(ll i=0;i<n;i++)
    {
        cin>>A[i];
    }
    ll s=1000;
    for(ll i=0;i<n-1;i++)
    {
        ll j=0;
        if(A[i]<A[i+1])j=s/A[i];
        s+=(A[i+1]-A[i])*j;        
    }
    cout<<s<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    // cin>>t;
    while(t--)
    {
        code();
    }
}