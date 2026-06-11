/*** author: yuji9511 ***/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lpair = pair<ll, ll>;
const ll MOD = 1e9+7;
const ll INF = 1e18;
#define rep(i,m,n) for(ll i=(m);i<(n);i++)
#define rrep(i,m,n) for(ll i=(m);i>=(n);i--)
#define printa(x,n) for(ll i=0;i<n;i++){cout<<(x[i])<<" \n"[i==n-1];};
void print() {}
template <class H,class... T>
void print(H&& h, T&&... t){cout<<h<<" \n"[sizeof...(t)==0];print(forward<T>(t)...);}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll K,Q;
    cin >> K >> Q;
    ll d[5010];
    rep(i,0,K) cin >> d[i];

    while(Q--){
        ll N,X,M;
        ll d2[5010];
        cin >> N >> X >> M;
        rep(i,0,K) d2[i] = d[i] % M;
        ll sum = 0;
        rep(i,0,K) sum += d2[i];
        ll zero = 0;
        rep(i,0,K){
            if(d2[i] == 0) zero++;
        }
        ll amari = (N-1) % K;
        ll cnt = (N-1) / K;
        ll val = X + sum * cnt;
        ll diff = val / M - X / M;
        ll ans = diff + zero * cnt;
        ans = K * cnt - ans;
        ll cur = val % M;
        rep(i,0,amari){
            if(cur < (cur + d2[i]) % M){
                ans++;
            }
            cur = (cur + d2[i]) % M;
        }
        print(ans);




    }
    

}