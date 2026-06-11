#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
//cout << setprecision(20) << 

int main() {
    ll n; cin >> n;
    vector<pair<ll, ll>> v(n);
    for (int i = 0; i < n; ++i) {
        ll a, b; cin >> a >> b;
        v[i] = make_pair(b, a);
    }
    sort(v.begin(), v.end());

    ll time = 0;
    for (int i = 0; i < n; ++i) {
        pair<ll, ll> front = v[i];
        if (time + front.second > front.first) {
            cout << "No"<< endl;
            return 0;
        }
        time += front.second;
    }
    cout << "Yes" << endl;
}