#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define ll long long
#define pii pair<int,int>


void test_case()
{
    ll ans=0,n,k, mod=1e9+7;
    cin>>n>>k;
    for(ll i=k;i<=1+n;i++) {
        ll mn,mx;
        mn = i*(i-1)/2;
        mx = n*i - mn;
        ans =(ans +  mx - mn + 1)%mod;
    }
    cout<<ans;
}

int main()
{
    fastio
//    int t;
//    cin>>t;
//    while(t--)
    test_case();
}
