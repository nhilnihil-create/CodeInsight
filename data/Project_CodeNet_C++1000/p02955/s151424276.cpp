#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(c) (c).begin(),(c).end()
#define RALL(c) (c).rbegin(),(c).rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

const ll INF = 1e18 + 10;

int N, K;

int main() {
    cin >> N >> K;
    vector<ll> a(N);
    rep(i,N) cin >> a[i];
    ll sum = 0;
    rep(i,N) sum += a[i];
    set<ll> candidates;
    for(int i= 1; i*i<=sum; ++i) {
        if(sum%i == 0) {
            candidates.insert(i);
            candidates.insert(sum/i);
        }
    }
    ll ans = 1;
    for (ll x : candidates) {
        ll need;
        vector<ll> r(N);
        rep(i,N) r[i] = a[i]%x;
        sort(ALL(r));
        ll B =0;
        rep(i,N) B += x-r[i];
        ll A = 0;
        need = INF;
        rep(i,N) {
            A += r[i];
            B -= x-r[i];
            need = min(need, max(A,B));
        }
        if (need <= K) ans = max(ans,x);
    }
    cout << ans << endl;
}