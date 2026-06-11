#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    ll N;

    cin >> N;
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    int cnt = 1, dnum = 0;
    rep(i, N) {
        if(a[i] == cnt) {
            cnt++;
        } else {
            dnum++;
        }
    }
    if(N == dnum) {
        cout << -1 << endl;
    } else {
        cout << dnum << endl;
    }
    return 0;
}
