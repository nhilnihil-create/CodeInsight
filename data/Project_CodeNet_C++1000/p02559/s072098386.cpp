#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#define ll long long
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pll pair<ll,ll>
#define pii pair<int,int>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define endl '\n'
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))

using namespace std;

using namespace atcoder;

int main(){
    int n,q;
    cin >> n >> q;
    fenwick_tree<ll> fen(n);
    rep(i,n){
        ll x;
        cin >> x;
        fen.add(i,x);
    }
    rep(i,q){
        ll tp;
        cin >> tp;
        if(tp==0){
            ll p,x;
            cin >> p >> x;
            fen.add(p,x);
        }
        else{
            ll l,r;
            cin >> l >> r;
            cout << fen.sum(l,r) << endl;
        }
    }
    return 0;
}