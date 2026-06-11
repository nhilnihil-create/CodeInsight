#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;

#define rep(i,n) for(ll i=0;i<ll(n);i++)
#define YESNO(T) if(T){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define yesno(T) if(T){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}
#define YesNo(T) if(T){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
const double pi = 3.14159265358979;



int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n,m;
    cin >> n >> m;

    priority_queue<ll> p;
    for (ll i = 0;i < n;i++){
        ll x;
        cin >> x;
        p.push(x);
    }

    rep(i,m){
        ll x = p.top();
        p.pop();
        x /= 2;
        p.push(x);
    }

    ll ans = 0;
    while (!p.empty()){
        ans += p.top();
        p.pop();
    }

    cout << ans << endl;

}