#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    ll n,a,b;
    cin>>n>>a>>b;

    ll ans=0;

    if(abs(a-b)%2==0)
    {
        ans = abs(a-b)/2;
    }
    else
    {
        ans=(abs(a-b)+2*(min(min(a-1,n-a),min(b-1,n-b))+1))/2;
    }

    cout<<ans<<"\n";    

    return 0;
}
