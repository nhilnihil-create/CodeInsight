#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)
int main() {
    ll n, k;
    cin >> n >> k;
    vector<int>a(n);
    rep(i, n) {
        cin >> a[i];
        a[i]--;
    }
    vector<bool> seen(n, false);
    vector<int>c(0);
    int now = 0;
    seen[now] = true;
    c.push_back(now);
    int st;
    while (true) {
        now = a[now];
        if (seen[now] == true) {
            st = now;
            break;
        }
        seen[now] = true;
        c.push_back(now);
        //cout << now << endl;
    }
    if (k < c.size()) {
        cout << c[k] + 1 << endl;
        return 0;
    }
    rep(i, c.size()) {
        if (c[i] == st) {
            cout << c[(k-i)%(c.size()-i) + i] + 1 << endl;
            break;
        }
    }
//    cout << c.size() << endl;
//    cout << c[k%c.size()] + 1 << endl;
    return 0;
}

