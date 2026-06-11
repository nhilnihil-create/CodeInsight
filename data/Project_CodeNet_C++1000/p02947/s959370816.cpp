#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s.at(i);
    }
    map<string, int> cnt;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        sort(s.at(i).begin(), s.at(i).end());
        if (cnt.count(s.at(i))) {
            ans += cnt.at(s.at(i));
            cnt.at(s.at(i))++;
        } else {
            cnt[s.at(i)] = 1;
        }
    }
    cout << ans << endl;
    return 0;
}
