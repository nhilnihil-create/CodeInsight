#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
int main() {
    int n; cin >> n;
    vector<ll> a(n+1), b(n);
    rep(i, n+1) cin >> a.at(i);
    rep(i, n) cin >> b.at(i);
    ll sum = 0;
    rep(i, n){
        sum += min(a.at(i), b.at(i));
        b.at(i) -= min(a.at(i), b.at(i));
        sum += min(a.at(i+1),b.at(i));
        a.at(i+1) -= min(a.at(i+1), b.at(i));
    }
    cout << sum << endl;
    return 0;
}