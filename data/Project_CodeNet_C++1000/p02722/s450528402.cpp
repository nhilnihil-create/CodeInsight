#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define rep(i,n); for(long long i = 0;i < (n);i++)
using ll = long long;
using P = pair<long long,long long>;
template <class T> using vec = vector<T>;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n; cin >> n;
    if(n == 2){
        cout << 1 << endl;
        return 0; 
    }
    vec<ll> div;
    for(ll i=2;i*i<=n;i++){
        if(!(n%i)){
            div.emplace_back(i);
            if(i*i != n)div.emplace_back(n/i);
        }
    }
    div.emplace_back(n);
    ll ans = 1;
    for(auto k : div){
        ll m = n;
        while(m%k==0)m/=k;
        if(m%k==1)ans++;
    }
    for(ll i=2;i*i<n;i++){
        if(!((n-1)%i))ans += 2;
        if(i*i == n-1)ans--;
    }
    cout << ans << endl;
}