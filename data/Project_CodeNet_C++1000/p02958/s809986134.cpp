#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
const int mod = 1e9 + 7, A = 1e5 + 2;

int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i], b[i] = a[i];
    }
    sort(b, b + n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) cnt++;
    }
    cout << (cnt > 2 ? "NO" : "YES");
    return 0;
}
