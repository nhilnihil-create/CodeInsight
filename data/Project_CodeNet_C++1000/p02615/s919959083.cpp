#include <bits/stdc++.h>
using ll = long long;
using namespace std;
ll GCD(ll a, ll b){ return a ? GCD(b % a, a) : b; }
int main(){
    int n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a.begin(),a.end(),greater<>());
    ll ans = 0;
    int cnt = 2;
    ans += a[0];
    for(int i=1; cnt<n; i++){
        ans += a[i];
        cnt++;
        if(cnt<n){
            ans+=a[i];
            cnt++;
        }
    }
    cout<<ans<<endl;
}