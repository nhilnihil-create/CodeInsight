#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define all(v) v.begin(),v.end()
#define pb push_back
#define rep(p,a,b) for(ll p=a ; p<b ; p++)
#define F first
#define S second
using namespace std;


int main()
{
    ll t,i,j,k,ans,n,x;

    //cin>>t;
    t=1;
    while(t--)
    {
        cin>>k>>x;
        if(500*k>=x)cout<<"Yes";
        else cout<<"No";
    }
    return 0;
}

