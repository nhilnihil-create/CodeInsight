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
    cin >> n;
    vector<int>sq(n);
    rep(i, n)cin >> sq[i];
    int cnt = 0;
    for (int i = 1; i < n - 1; i++) {
        if (sq[i - 1] > sq[i] && sq[i]  > sq[i + 1] || sq[i - 1] < sq[i] && sq[i]< sq[i + 1])cnt++;
    }
    cout << cnt << endl;
    return 0;
}