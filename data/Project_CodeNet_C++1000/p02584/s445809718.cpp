#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <unordered_map>
typedef long long ll;
using namespace std;
const int mod=1e9+7;

ll solve(){
    ll x,k,d;
    cin>>x>>k>>d;
    x=abs(x);
    if(x/d <= k){
        k-=x/d;
        x%=d;
        if(k%2) return d-x;
        return x;
    }
    return x-k*d;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int t=1;
    //cin>>t;
    while(t--) cout<<solve()<<'\n';
    //while(t--) solve(),cout<<'\n';
    return 0;
}
