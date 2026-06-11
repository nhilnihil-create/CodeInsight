#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main()
{
    ll a,b;
    cin>>a>>b;
    if(a>b){
    for(ll i=0;i<a;i++)
    {
        cout<<b;
    }
     return 0;
    }
    else
    {
        for(ll i=0;i<b;i++)
    {
        cout<<a;
    }
     return 0;
    }
}