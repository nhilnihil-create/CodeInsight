#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll=long long;
using vi=vector<int>;
using vll=vector<ll>;
#define MOD 1000000007

int main(){
    int n;
    cin >> n;
    vll a(n);
    map<ll,ll> mp;
    map<ll,ll> mp2;
    for(ll i=0;i<n;i++){
        cin >> a[i];
        mp[i+a[i]]++;
        mp2[i-a[i]]++;
    }
    ll ans=0;
    for(auto x:mp){
        ans+=x.second*mp2[x.first];
    }
    cout << ans << endl;
}