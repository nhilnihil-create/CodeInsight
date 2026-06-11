#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
using ll = long long;

int main() {
    int n;
    cin >> n;

    set<ll> s;

    ll a;
    rep(i,n) {
        cin >> a;
        if (s.find(a) != s.end()) {
            cout << "NO" << endl;
            return 0;
        }
        s.insert(a);
    }

    cout << "YES" << endl;
    return 0;
}