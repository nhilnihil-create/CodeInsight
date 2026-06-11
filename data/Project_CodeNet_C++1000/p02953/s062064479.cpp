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
    ll maxim = 0;
    cin >> n;
    bool ans = true;
    vector<ll>arr(n);
    rep(i, n)cin >> arr[i];
    for (int i = n - 1; i > 0; i--) {
        if (arr[i] < arr[i - 1]) {
            if (arr[i] == (arr[i - 1] - 1))arr[i - 1]--;
            else { ans = false; break; }
        }
    }
    if (ans) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}