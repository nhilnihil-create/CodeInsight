//g++  7.4.0

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll N; cin>>N;
    
    ll fac[N + 1] = {0};
    
    for(ll i=2;i<N;++i)
    {
        for(ll j=i;j<=N;j += i)
        {
            fac[j]++;
        }
    }
    
    ll ans = 0;
    for(ll i=1;i<N;++i)
    {
        ll req = N - i;
        //all possible factors of req
        ans += (fac[req] + 1);
    }
    
    cout<<ans<<endl;
}