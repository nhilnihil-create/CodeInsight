#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll INF = 1e17;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> a(n+1);
    rep(i,n+1) cin >> a[i];
    vector<ll> l(n+1, 1), r(n+1, INF);
    l[n] = a[n];
    r[n] = a[n];
    for(int i = n; i >= 0; --i){
        chmax(l[i], 1LL);
        chmin(r[i], (i <= 40 ? (1LL << i) : INF));
        if(l[i] > r[i]){
            cout << -1 << endl;
            return 0;
        }
        if(i > 0){
            chmax(l[i-1], (l[i]+1)/2 + a[i-1]);
            chmin(r[i-1], r[i] + a[i-1]);
        }
    }
    if(l[0] > 1 || r[0] < 1){
        cout << -1 << endl;
        return 0;
    }
    ll ans = 0, num = 1;
    rep(i,n+1){
        if(l[i] > num || num > r[i]){
            cout << -1 << endl;
            return 0;
        }
        ans += num;
        num -= a[i];
        if(num < 0){
            cout << -1 << endl;
            return 0;
        }
        if(i < n){
            if(num*2 < l[i+1] || num > r[i+1]){
                cout << -1 << endl;
                return 0;
            }
            num = min(num*2, r[i+1]);
        }
    }
    cout << ans << endl;
    return 0;
}
