#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0; i < (ll)(n); i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1LL << 60;

vector<ll> fact(ll n){
    vector<ll> res;
    for(ll i=1; i*i<=n; i++){
        if(n%i!=0) continue;
        res.push_back(i);
        if(i*i!=n) res.push_back(n/i);
    }
    return res;
}
int main(){
    ll n;
    cin >> n;
    vector<ll> nfact = fact(n);
    ll ans = 0;
    for(ll f : nfact){
        if(f==1) continue;
        ll ncp = n;
        while(ncp % f == 0) ncp /=f;
        if(ncp%f==1) ans++;
    }
    ans += fact(n-1).size()-1;
    cout << ans << endl;
    return 0;
}