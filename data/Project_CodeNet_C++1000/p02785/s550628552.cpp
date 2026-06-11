#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
const int mod =1'000'000'007;

int main(){
    int n, k;
    cin >> n >> k;

    vi h(n);
    rep(i,n) cin >> h.at(i);
    sort(h.rbegin(), h.rend());

    ll ans = 0;
    REP(i,k,n) ans += h.at(i);
    cout << ans << endl;
    return 0;
}
