#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ar array
#define pii pair<int, int>

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, ans = 0;
    cin >> n;
    for (int i = 1, a; i <= n; i++) {
        cin >> a;
        ans += (a % 2 == 1 && i % 2 == 1);
    }
    cout << ans << '\n';
}
