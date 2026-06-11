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
    ll sum = 0;
    cin >> n;
    vector<int>city(n + 1), hero(n);
    rep(i, n + 1)cin >> city[i];
    rep(i, n)cin >> hero[i];
    for (int i = n - 1; i >= 0; i--) {
        if (city[i + 1] < hero[i]) {
            hero[i] -= city[i + 1];
            sum += city[i + 1];
            sum += min(city[i], hero[i]);
            city[i] -= min(city[i], hero[i]);
        }
        else {
            sum += min(city[i + 1], hero[i]);
        }
    }

    cout << sum << endl;
    return 0;
}