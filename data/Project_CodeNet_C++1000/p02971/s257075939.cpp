#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) {
        b[i] = a[i];
    }
    sort(b.begin(), b.end());

    rep(i,n) {
        if (a[i] == b[n-1]) cout << b[n-2] << endl;
        else cout << b[n-1] << endl;
    }

    return 0;
}