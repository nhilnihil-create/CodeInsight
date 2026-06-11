#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    ll h, n;
    cin >> h >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    ll sum = 0;
    bool f = 1;
    rep(i, n) {
        sum += a[i];
        if(h <= sum) {
            cout << "Yes" << endl;
            f = 0;
            break;
        }
    }
    if(f == 1) cout << "No" << endl;
    return 0;
}