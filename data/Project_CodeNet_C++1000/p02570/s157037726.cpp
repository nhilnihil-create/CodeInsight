#include <bits/stdc++.h>
using namespace std;
#define pb push_back
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int d, t, s;
    cin >> d >> t >> s;
    cout << (d <= t * s ? "Yes" : "No") << '\n';
    return 0;
}