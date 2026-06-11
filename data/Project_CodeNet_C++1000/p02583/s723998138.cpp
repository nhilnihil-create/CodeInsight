#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define F first
#define S second
#define pb push_back
#define mp make_pair

const int MOD = 1000000007;
const int N = 1e5 + 18;


int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    //cin >> t;
    while (t--) {
        //for (int tt = 1; tt <= t; tt++) {
        int n; cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int sum = 0;
        sort(a, a + n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                for (int k = j + 1; k < n; k++) {
                    if (a[i] == a[j] || a[j] == a[k]) continue;
                    if (a[i] + a[j] > a[k]) sum++;
                }
            }
        }
        cout << sum;
    }
    return 0;

}


