#include <bits/stdc++.h>
#define int long long int
using namespace std;
signed main()
{
    int A,B,C,K;
    cin>>A>>B>>C>>K;
    int ans=0;
    if(K>0)
    {
        ans+=min(K,A);
        K -=min(K,A);
    }
    if(K>0)
    {
        K -=min(K,B);
    }
    if(K>0)
    {
        ans -= min(K,C);
        K-= min(K,C);
        
    }
    
    cout<<ans;
    return 0;
}