#include <bits/stdc++.h>
#define FOR(i, x, y) for (int i = x; i < y; i++)
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll k, j;
    cin >> k;
    ll i, n, a;
    n = 1 << k;
    vector<ll> v;
    multiset<ll> s;
    for (i = 0; i < n; i++) {
        cin >> a;
        s.insert(-1 * a);
    }
    v.push_back(*s.begin());
    s.erase(s.begin());
    for (i = 0; i < k; i++) {
        vector<ll> temp;
        for (j = 0; j < v.size(); j++) {
            auto it = s.upper_bound(v[j]);
            if (it == s.end()) {
                cout << "No" << endl;
                return 0;
            }
            temp.push_back(*it);
            s.erase(it);
        }
        for (j = 0; j < temp.size(); j++) v.push_back(temp[j]);
        sort(v.begin(), v.end());
    }
    cout << "Yes" << endl;
    return 0;
}