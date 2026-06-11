#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> a(n);
    map<ll, ll> r, l;
    rep(i,n){
        cin >> a[i];
        r[i+a[i]]++;
        l[i-a[i]]++;
    }
    ll ans = 0;
    for(auto p : r){
        ans += p.second * l[p.first];
    }
    cout << ans << endl;
    return 0;
}
