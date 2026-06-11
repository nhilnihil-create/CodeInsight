#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;


int main() {
    int n, w,mins = 10000000;
    cin >> n;
    vector<int>rui(n + 1, 0);
    rep(i, n) {
        cin >> w;
        rui[i + 1] = rui[i] + w;
    }
    REP(i, n-1) {
        mins = min(mins, abs((rui[n] - rui[i]) - rui[i]));
    }
    cout << mins << endl;
    return 0;
}
