#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, k, d;
    cin >> n >> k;
    vector<int> check(n,0);
    vector<int> a;
    rep(i, k) {
        cin >> d;

        rep(j, d) {
            int tmp;
            cin >> tmp;
            a.push_back(tmp);
        }
    }
    rep(i, a.size()) { check[a[i] - 1] = 1; }
    cout << n - accumulate(check.begin(), check.end(), 0) << endl;
    return 0;
}