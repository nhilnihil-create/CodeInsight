/**
*    created: 10.05.2020 16:38:21
**/
#include <bits/stdc++.h>
#define int long long
const int INF = 1e18L + 5;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;

vector<int> p(100000,-1);

int dpt(int i) {
    if (p[i] == -1) return 0;
    else return dpt(p[i]) + 1;
}

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;

    int id, k, c;
    vector<vector<int>> cld(n);
    rep(i,n) {
        cin >> id >> k;
        rep(j,k) {
            cin >> c;
            cld[id].push_back(c);
        }
    }
    rep(i,n) {
        rep(j,cld[i].size()) {
            p[cld[i][j]] = i;
        }
    }

    //出力
    rep(i,n) {
        int d = dpt(i);
        cout << "node " << i << ": ";
        cout << "parent = " << p[i] << ", ";
        cout << "depth = " << d << ", ";

        if (d == 0) cout << "root" << ", " ;
        else if (cld[i].size() == 0) cout << "leaf" << ", ";
        else cout << "internal node" << ", ";

        if(cld[i].size() == 0) cout << "[]" << endl;
        else {
            cout << "[";
            rep(j,cld[i].size()) {
                if (j == cld[i].size() - 1) cout << cld[i][j] << "]" << endl;
                else cout << cld[i][j] << ", ";
            }
        }
    }
    return 0;
}
