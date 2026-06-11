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
    cin>>a>>b;
    if(b==1) 
    {
        cout<<"0";
        return 0;
    }
    ll ans=1;
    ll count=a;
    if(a>=b)
    {
        cout<<"1";
        return 0;
    }
    while(1)
    {
        if(count>=b) break;
        count-=1;
        count+=a;
        ans++;
    }
    cout<<ans;
    
}