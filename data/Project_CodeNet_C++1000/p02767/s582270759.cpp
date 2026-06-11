#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;

int main() {
    int n, ans, mini = 100000000;
    cin >> n;
    vector<int> x(n);
    rep(i, n) cin >> x[i];
    // int sum = accumulate(x.begin(), x.end(), 0);
    rep(i, 100) {
        int dist = 0;
        rep(j, n) { dist += (i - x[j]) * (i - x[j]); }
        if(mini > dist) {
            mini = dist;
            ans = i;
        }
        // cout << mini << endl;
    }
    cout << mini << endl;
    return 0;
}
