#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n,k;
    cin >> n >> k;

    vector<int> x(n,0);
    rep(i,k) {
        int d;
        cin >> d;
        vector<int> a(d,0);
        rep(j,d) {
            int a;
            cin >> a;
            x[a-1]++;
        }
    }

    int ans = 0;
    rep(i,n) {
        if (x[i] == 0) ans++;
    }

    cout << ans << endl;

}