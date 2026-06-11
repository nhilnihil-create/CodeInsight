#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> w(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i].second >> w[i].first;
    }
    sort(w.begin(), w.end());
    ll sum = 0;
    string ans = "Yes";
    for (int i = 0; i < n; i++) {
        sum += w[i].second;
        if (sum > w[i].first) {
            ans = "No";
            break;
        }
    }
    cout << ans << endl;
    return 0;
}