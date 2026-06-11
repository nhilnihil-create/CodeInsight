#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    string s;
    cin >> s;
    int n = s.size() + 1;
    vector<ll> a(n, 0);

    int k = 1, sum = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == '<') a[i + 1] = a[i] + 1;
    }

    for (int i = n - 2; i >= 0; i--) {
        if (s[i] == '>') a[i] = max(a[i+1] + 1, a[i]);
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) ans += a[i];
    cout << ans << endl;
}