#include<bits/stdc++.h>
#define ll long long
#define MAX 1000000000
#define INF 1000000 
#define M 1000000007
#define PI 2 * acos(0.0)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
int main(){
    fast_io 
    ll n;
    cin>>n;
    ll a[n];
    for(ll i = 0;i<n;i++) cin>>a[i];
    map<ll,ll> mp;
    for(ll i = 0;i<n;i++){
        mp[a[i]]++;
    }
    ll ans1 = 0;
    for(auto x : mp){
        ll k = x.second;
        ll sum = (k*(k-1))/2;
        ans1 += sum;
    }
    for(ll i = 0;i<n;i++){
        ll r = mp[a[i]] - 1;
        cout<<ans1-r<<endl;
    }
    return 0;
}
