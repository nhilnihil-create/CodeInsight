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
    ll n,m,i,a=0,b=0,k;
    cin>>n>>m>>k;
    a=n-k;
    cout<<max((ll)0,a)<<" ";
    k-=n;
    if(k>0) 
    {
        a=m-k;
        cout<<max((ll)0,a);
    }
    else cout<<m;
}