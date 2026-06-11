#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;


int main() {
    int n;
    double sum = 0.0;
    cin >> n;
    vector<double>v(n);
    rep(i, n)cin >> v[i];
    sort(all(v));
    sum =( v[0] + v[1] ) / 2;
    for (int i = 2; i < n;i++) {
        sum = (sum + v[i]) / 2;
    }
    cout << fixed << setprecision(8) << sum << endl;
    return 0;
}