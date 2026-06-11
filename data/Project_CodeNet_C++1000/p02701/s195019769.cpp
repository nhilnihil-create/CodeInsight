#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

void solve() {
    map<string, int> keihin;
    int n;
    cin >> n;
    rep(i,n) {
        string s;
        cin >> s;
        keihin[s]++;
    }

    int ans = 0;
    for (auto itr = keihin.begin(); itr != keihin.end(); itr++) {
        ans++;
    }

    cout << ans << endl;
}

int main() {
    solve();
    return 0;
}
