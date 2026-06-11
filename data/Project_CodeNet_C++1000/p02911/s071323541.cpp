#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;


int main() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int>cusr(n,0);
    int a;
    rep(i, q) {
        cin >> a;
        cusr[a - 1]++;
    }
    int succsess = q - k + 1;
    bool ans = false;
    for (auto s : cusr) {
        if (s >= succsess)ans = true;
        else ans = false;
        if (ans) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    return 0;
}