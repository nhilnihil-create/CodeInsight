#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
using P=pair<int,int>;
ll __lcm(ll a,ll b){
    ll ab=a*b;
    ll g=__gcd(a,b);
    return ab/g;
}
int two(ll x){
    int cnt=0;
    while(x%2==0){
        x/=2;
        cnt++;
    }
    return cnt;
}
int main() {
    ll n,m;cin>>n>>m;
    vector<ll> a(n);
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    int flag=1;
    for(int i=0;i<n-1;i++){
        if(two(a[i])!=two(a[i+1])) flag=0;
    }
    if(flag==0){
        cout<<0<<endl;
    }else{
        ll l=1;
        for(ll i=0;i<n;i++){
            l=__lcm(l,a[i]);
            if(l/2>m){
                cout<<0<<endl;
                return 0;
            }
        }
        ll ans;
        
        ans=(m-(l/2))/l+1;
        cout<<ans<<endl;
        }

}