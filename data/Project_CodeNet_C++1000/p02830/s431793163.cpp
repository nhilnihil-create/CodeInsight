#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;


int main() {
    int a;
    string b, c,ans="";
    cin >> a >> b >> c;
    rep(i, a) {
        ans += b[i];
        ans += c[i];
    }
    cout << ans << endl;
    return 0;
}