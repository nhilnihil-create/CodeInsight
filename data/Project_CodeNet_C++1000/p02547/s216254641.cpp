//g++  7.4.0

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll N; cin>>N;
    ll D1[N],D2[N];
    
    for(ll i=0;i<N;++i)
        cin>>D1[i]>>D2[i];
    
    for(ll i=2;i<N;++i)
    {
        if((D1[i] == D2[i]) && (D1[i - 1] == D2[i - 1]) && (D1[i - 2] == D2[i - 2]))
        {
            cout<<"Yes"<<endl;
            return(0);
        }
    }
    
    cout<<"No"<<endl;
}