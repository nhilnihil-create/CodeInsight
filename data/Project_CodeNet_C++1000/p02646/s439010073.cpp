#include<bits/stdc++.h>
#define pb push_back
#define vl vector
#define ll long long
#define fast std::ios::sync_with_stdio(false)
using namespace std;

int main()
{
    fast;
    ll a,b,v,w,t;
    cin>>a>>v>>b>>w>>t;
    ll d=abs(a-b);
    if(v<w) cout<<"NO";
    else if(d<=(v-w)*t) cout<<"YES";
    else cout<<"NO";
}
