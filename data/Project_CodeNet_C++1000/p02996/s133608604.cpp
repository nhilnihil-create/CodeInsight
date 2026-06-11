#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n; cin >> n;
    multimap<int, int> mp;
    rep(i,n) {
        int a, b;
        cin >> a >> b;
        mp.insert(make_pair(b, a));
    }
    ll cnt = 0;
    for (auto x : mp) {
        cnt += x.second;
        if (x.first < cnt) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}