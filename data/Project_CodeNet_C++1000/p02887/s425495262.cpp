#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); ++i)
double const PI = 3.1415926535897932384626433;

int main() {
    ll n, cnt = 1;
    string s;
    cin >> n >> s;
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i - 1])
            continue;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}