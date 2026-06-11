#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll a,v,b,w,t;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>a>>v>>b>>w>>t;
    if(a<b)
    {
        a+=v*t;
        b+=w*t;
        if(a>=b)
            cout<<"YES";
        else
            cout<<"NO";
        return 0;
    }
    else if(a==b)
    {
        cout<<"YES";
        return 0;
    }
    else if(a>b)
    {
        a-=v*t;
        b-=w*t;
        if(a<=b)
            cout<<"YES";
        else
            cout<<"NO";
        return 0;
    }
    return 0;
}
