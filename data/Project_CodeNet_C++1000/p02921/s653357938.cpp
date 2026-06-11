#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize ("-ffloat-store")  
#pragma GCC optimize ("-fno-defer-pop")
typedef long long int ll; 
typedef long double ld; 

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s,t;
    cin>>s>>t;
    ll ans = 0;
    for(ll i=0;i<s.size();i++)
    {
        if(s[i]==t[i])
        {
            ans++;
        }
    }

    cout<<ans<<endl;

}