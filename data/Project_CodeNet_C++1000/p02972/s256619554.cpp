#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
const int mod = 1e9 + 7, A = 2e5 + 2;

int ans[A];
int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> v;
    for (int i = n; i > 0; i--) {
        int val = 0;
        for (int j = i + i; j <= n; j += i) {
            val += ans[j];
        }
        if (val % 2 != a[i])
            ans[i] = 1, v.pb(i);
    }
    cout << v.size() << '\n';
    for (auto i : v)
        cout << i << ' ';
    return 0;
}