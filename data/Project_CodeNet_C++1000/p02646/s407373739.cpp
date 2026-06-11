#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int a,v,b,w,t;
    cin>>a>>v>>b>>w>>t;
    if(w>=v)
    {
        cout<<"NO";
        return 0;
    }
    if(abs(a-b)<=abs(v-w)*t)
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    return 0;
}
