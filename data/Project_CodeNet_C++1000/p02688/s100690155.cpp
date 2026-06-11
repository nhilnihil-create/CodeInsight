#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> snuke(n);
    rep(i,k) {
        int d;
        cin >> d;
        rep(j,d) {
            int a;
            cin >> a;
            a--;
            snuke[a]++;
        }
    }
    int ans = 0;
    rep(i,n) {
        if (snuke[i] == 0) ans++;
    }
    cout << ans << endl;
    return 0;
}