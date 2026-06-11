#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
typedef long long ll;
typedef pair<ll,ll> prl;
typedef vector<ll> vcl;
typedef map<ll,ll> mapl;
typedef unordered_map<ll,ll> umap;
#define pb push_back
#define all(v) v.begin(), v.end()
#define rep(i,a,b) for(ll i=a;i<=b;i++)
#define repi(i,a,b) for(int i=a;i<=b;i++)
#define repr(i,a,b) for(ll i=a;i>=b;i--)
#define reps(i,v) for(ll i=0;i<v.size();i++)
template<typename T> void chmin(T &a, const T &b) { a = min(a, b); }
template<typename T> void chmax(T &a, const T &b) { a = max(a, b); }
const ll mod = 1e9+7;

//Binary_Indexed_Tree (Range_Sum_Query)
//(1-indexed)
const ll max_n = 1e6+5;
ll n, bit[max_n];
//i番目(1-indexed)までの和
ll sum(ll ii){
    ll sm = 0;
    while(ii > 0){
        sm += bit[ii];
        ii -= ii & -ii;
    }
    return sm;
}
//i番目(1-indexed)にxを加える
void add(ll ii, ll x){
    while(ii <= n){
        bit[ii] += x;
        ii += ii & -ii;
    }
}

int main() {
    // your code goes here
    ll q;
    cin >> n >> q;
    rep(i,1,n){
        ll x;
        cin >> x;
        add(i,x);
    }
    rep(i,1,q){
        ll a,b,c;
        cin >> a >> b >> c;
        if(a==0) add(b+1,c);
        else cout << sum(c)-sum(b) << endl;
    }
    return 0;
}