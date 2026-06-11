#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int a,b,v,w,t,d,e;
    cin>>a>>v;
    cin>>b>>w;
    cin>>t;
    d=abs(a-b);
    e=(v-w)*t;
    if(d<=e)
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
    }
    return 0;
}
