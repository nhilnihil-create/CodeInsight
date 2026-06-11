#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    int n, m;
    cin >> n >> m;
    rep(i, m) {
        int a;
        cin >> a;
        n -= a;
    }
    if(n >= 0) cout << n << endl;
    else cout << -1 << endl;
}
