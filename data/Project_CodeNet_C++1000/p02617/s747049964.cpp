#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX 2000009
#define MOD 1000000007
#define endl '\n'
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ll n;
    cin>>n;
    ll ans=0;
    for(ll i=1;i<=n;i++){
        ans+=(i*(i+1))/2;
    }
    //cout<<ans<<endl;
    for(ll i=1;i<=n-1;i++){
        ll a,b;
        cin>>a>>b;
        if(a>b){
            swap(a,b);
        }
        ans-=(a*(n-b+1));
    }
    cout<<ans<<endl;
    return 0;
}