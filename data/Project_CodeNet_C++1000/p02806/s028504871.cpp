#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
using namespace std;

void solve() {
    int n; cin >> n;
    vector<pair<string, int>> vp(n);
    rep(i, 0, n) cin >> vp[i].first >> vp[i].second;
    string x; cin >> x;

    int ans = 0; int f = 0;
    rep(i, 0, n){
        if(f) ans += vp[i].second;
        if(vp[i].first == x) f = 1;
    }
    cout << ans << "\n";
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    solve();
    return 0;
}
 
