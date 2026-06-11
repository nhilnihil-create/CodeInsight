#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pi pair<int, int>
#define pb push_back
#define fr first
#define sc second
#define endl '\n'

const int mxn = 1e6 + 5;
const ll MOD =  1e9 + 7;
int arr[mxn];
int n, m, k, q;
string s, t;

void solve() {
    int ans = mxn;
    cin >> s >> t;
    for (int i = 0; i < s.size() - t.size() + 1; i++) {
        int curr = 0;
        for (int j = 0; j < t.size(); j++) curr += (s[i + j] != t[j]);
        ans = min(ans, curr);
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}
