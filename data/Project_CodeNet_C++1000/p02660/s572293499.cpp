#include <bits/stdc++.h>
#define rep(i, n)	for(int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

vector<pair<ll,ll>> prime_factorize(ll n){
    vector<pair<ll,ll>>res;
    for(ll a=2;a*a<=n;a++){
        if(n%a!=0) continue;
        ll ex=0;
        while(n%a==0){
            ex++;
            n/=a;
        }
        res.push_back({a, ex});
    }
    if(n!=1) res.push_back({n, 1});
    return res;
}

int main(){
    ll n;
    cin>>n;
    ll ans=0;
    auto p=prime_factorize(n);

    // for(pair<ll,ll> x : p){
    //     cout<<x.first<<":"<<x.second<<endl;
    // }
    for(int i=0;i<p.size();i++){
        int cnt=1;
        while(p[i].second>=cnt){
            p[i].second-=cnt;
            cnt++;ans++;
        }
    }
    cout<<ans<<endl;
}