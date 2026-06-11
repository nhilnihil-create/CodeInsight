#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main ()
{
    ll a,b,v,w,t;
    cin>>a>>v;
    cin>>b>>w;
    cin>>t;
    if(v==w)
    {
        cout<<"NO";
    }
    else
    {
        ll k=abs(b-a);
        if(k<=(v-w)*t)
        {
            cout<<"YES";
        }
        else
        {
            cout<<"NO";
        }
       
    }
    
    return 0;
}