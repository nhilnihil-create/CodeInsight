//https://atcoder.jp/contests/abc148/tasks/abc148_e
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    ll n;cin>>n;
    ll ans=0;
    if(n&1) cout<<0<<endl;
    else
    {
        n/=2;
        while(n)
        {
            n/=5;
            ans+=n;
        }
        cout<<ans<<endl;
    }
    
}
