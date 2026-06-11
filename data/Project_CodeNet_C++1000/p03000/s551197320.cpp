#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, x, d = 0, cnt = 0;
    cin >> n >> x;
    vector<int> L(n);
    rep(i, n) cin >> L[i];
    int ans;

    cnt += 1;
    rep(i, n) {
        if(d + L[i] > x)
            break;
        d += L[i];
        cnt += 1;
    }

    cout << cnt << endl;
    return 0;
}