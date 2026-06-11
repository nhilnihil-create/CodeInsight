#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
typedef long long int ll;
const int INF = 1000000000;
const double PI = 3.1415926535;

ll Combination(ll n, ll r) {
    ll molecule = 1;
    ll denominator = 1;
    for (ll i = 0; i < r; i++) {
        molecule *= n - i;
        denominator *= r - i;
    }
    return (molecule / denominator);
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> jobs(m);
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        // a > mの場合無意味、例外処理
        if (a > m) continue;
        jobs[a - 1].push_back(b);
    }

    priority_queue<int> pque;
    ll ans = 0;
    rep(i, m) {
        for (auto b : jobs[i]) {
            pque.push(b);
        }
        if (!pque.empty()) {
            ans += pque.top();
            pque.pop();
        }
    }
    cout << ans << endl;
    return 0;
}