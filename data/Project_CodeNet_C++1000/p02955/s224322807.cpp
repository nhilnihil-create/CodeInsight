#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    ll sum = 0;
    rep(i,n){
        cin >> a[i];
        sum += a[i];
    }
    set<ll> st;
    for(ll i = 1; i*i <= sum; ++i){
        if(sum%i == 0){
            st.insert(i);
            st.insert(sum/i);
        }
    }
    ll ans = 1;
    for(auto x : st){
        ll cost = 0, total = 0;
        vector<ll> rest(n);
        rep(i,n){
            rest[i] = a[i] % x;
            total += rest[i];
        }
        sort(rest.begin(), rest.end());
        ll l = n - total / x;
        rep(i,l) cost += rest[i];
        if(cost <= k) chmax(ans, x);
    }
    cout << ans << endl;
	return 0;
}
