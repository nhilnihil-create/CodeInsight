#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll a,v,b,w,t;
    cin>>a>>v>>b>>w>>t;
   // bool f=false;
    int dis=abs(a-b);
    int par=(v-w);
    if(par*t>=dis){
        cout<<"YES";
    }
    else
        cout<<"NO";
}

