#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0; i<n; ++i)
#define rep1(i,n) for(ll i=1; i<=n; ++i)

int d[61][200001];
int main() {
    ll N, K, t=1;
    cin >> N >> K;
    rep1(i,N) cin >> d[0][i];
    rep(b,60) rep1(i,N)
        d[b+1][i] = d[b][d[b][i]];
    rep(i,60)
        if (K & (1LL << i)) t = d[i][t];
    cout << t << endl;
}
