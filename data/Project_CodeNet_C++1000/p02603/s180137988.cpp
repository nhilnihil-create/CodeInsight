#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    int n;
    cin >> n;
    vi a(n);
    rep(i, n) cin >> a.at(i);
    ll x = 1000;
    for (int i = 1; i < n; i++) {
        int b = a.at(i-1);
        int s = a.at(i);
        if(b < s) x = x/b * s + x%b;
    }
    cout << x << endl;
    return 0;
}