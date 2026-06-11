#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    vector<vector<int>> x(n+1, vector<int>(n));
    vector<vector<int>> y(n+1, vector<int>(n));

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] != 0)
            for (int j = 1; j <= a[i]; j++) cin >> x[i][j] >> y[i][j];
    }

    int ans = 0;
    for (int is = (1<<n)-1; is >=0 ; is--) {
        int tmp = 0;

        bool okflag = true;
        for (int i=1; i<=n; i++) {
            if(is>>(i-1)&1) {
                if (a[i] != 0)
                    for (int j = 1; j <= a[i]; j++) {
                        if ((is>>(x[i][j]-1)&1) != (y[i][j])) {
                            okflag = false;
                            break;
                        }
                    }
            }
            if(!okflag) break;
        }
        if(!okflag) continue;
        rep(k, n) {
            if (is>>k&1) tmp++;
        }
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}