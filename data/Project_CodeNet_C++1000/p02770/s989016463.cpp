#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (ll)(n); i++)
#define repi(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1LL << 60;

int divceil(int a, int b){
    return (a+b-1) / b;
}
int main(){
    int k,q; cin >> k >> q;
    vector<int> d(k);
    rep(i,k) cin >> d[i];
    rep(qi,q){
        int n,x,m;
        cin >> n >> x >> m;
        ll last = x;
        ll eq=0;
        rep(i,k){
            ll num = divceil(n-1-i,k);
            last += (d[i]%m)*num;
            if(d[i]%m==0)eq+=num;
        }
        ll ans = n-1 - (last/m - x/m) - eq;
        cout << ans << endl;
    }
    
    return 0;
}
