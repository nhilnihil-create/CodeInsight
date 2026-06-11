#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using pii = pair<int, int>;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);


    int d, t, s; cin >> d >> t >> s;


    cout << (d <= s * t ? "Yes" : "No") << endl;


    return 0;
}
