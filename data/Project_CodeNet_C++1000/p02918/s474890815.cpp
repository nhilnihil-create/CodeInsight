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
    
    ll n,k;
    cin>>n>>k;

    string s;
    cin>>s;

    vector <ll> vec;

    vec.push_back(0);
    ll ans = 0;
    for(ll i=1;i<s.size();i++)
    {
        if(s[i]!=s[vec.back()])
        {
            ans += i-vec.back()-1;
            vec.push_back(i);
        }
    }
    ans += n-vec.back()-1;
    ll p = vec.size();
    
    for(ll i=1;i+1<vec.size();i+=2)
    {
        p-=2;
        ans += 2;
        k--;
        if(k==0)
            break;
    }

    if(p>=2)
    {
        if(k>0)
        {
            ans += 1;
        }
    }

    cout<<ans<<endl;

}