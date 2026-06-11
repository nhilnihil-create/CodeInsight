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

ll P(int num) {
    ll res = 1;
    for (int i = 1; i <= n; i++) (res *= num) %= MOD;
    return res;
}

void solve() {
    cin >> n;
    cout << (P(10) - (((P(9) * 2  % MOD) - P(8) + MOD) % MOD) + MOD) % MOD << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    //cin >> T;
    while(T--) solve();
    return 0;
}
