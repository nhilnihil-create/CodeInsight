#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,n) for(int i=a;i<n;i++)
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define lli long long
#define all(c) (c.begin(),c.end())
#define sz(s) (int)(s).size()
const int MOD = 1000000007;
const int MX = 2e5 + 5;
const lli INF = 1e18;


void solve() {
    int n;
    cin >> n;
    vector<lli> arr(n + 1);

    FOR(i, 1, n + 1)
    {   arr[i]++;
        lli j = (lli)i * 2;
        while (j <= n)
        {
            arr[j]++;
            j += i;
        }
    }
    lli ans = 0;

    FOR(i, 1, n + 1) {
        ans += (lli)(i * arr[i]);
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

#ifndef ONLINE_JUDGE

    freopen("input.txt", "r", stdin);

    freopen("output.txt", "w", stdout);
#endif

    solve();




    return 0;
}
