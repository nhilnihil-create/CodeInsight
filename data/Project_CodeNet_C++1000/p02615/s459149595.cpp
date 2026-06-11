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
    rep(i,n) cin >> a[i];
    priority_queue<P> pq;
    sort(a.rbegin(), a.rend());
    pq.push(P(a[0], a[0]));
    ll ans = 0;
    for(int i = 1; i < n; ++i){
        P p = pq.top();
        pq.pop();
        ans += p.first;
        pq.push(P(a[i], p.first));
        pq.push(P(a[i], p.second));
    }
    cout << ans << endl;
    return 0;
}