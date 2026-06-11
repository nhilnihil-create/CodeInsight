#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)
int main() {
    ll n;
    ll ans = 0;
    cin >> n;
    vector<pair<ll, ll>>p(n);
    rep(i, n) {
        cin >> p[i].second >> p[i].first;
    }
    sort(p.begin(), p.end());
    ll t = 0;
    string a = "Yes";
    rep(i,n) {
        //cout << t << ',' << p[i].first << ',' << p[i].second << endl;
        t += p[i].second;
        if (t <= p[i].first) {
        }else {
            a = "No";
            //cout << p[i].second;
            break;
        }
    }
    cout << a << endl;
    return 0;
}

