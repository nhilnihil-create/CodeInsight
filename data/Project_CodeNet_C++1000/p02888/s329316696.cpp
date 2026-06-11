#include<bits/stdc++.h>
#define int long long int
#define endl "\n"
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(),a.end());
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n - 1; j++) {
                int sum = a[i] + a[j];
                int p = lower_bound(a.begin(),a.end(),sum) - a.begin();
                //cout<<p<<endl;
                p--;
                count += p - j;
            }
        }
        cout << count << endl;
    }
    return 0;
}