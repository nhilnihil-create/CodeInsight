#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll inf= 1e9;
void solution(){
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(auto &x: arr)
        cin>>x;
    ll L= arr[0],R=arr[0];
    ll ans = inf;
    for(auto &x: arr){
        L = min(L,x);
        R = max(R,x);
    }
    for(ll i=L;i<=R;++i){
        ll cost=0;
        for(ll j=0;j<n;++j)
            cost += (arr[j]- i)*(arr[j]-i);
        ans = min(cost,ans);
    }
    cout<<ans;

}
int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        cerr.tie(0);
        /*ll t;
        cin>>t;
        while(t--)*/
                solution();
        return 0;
}