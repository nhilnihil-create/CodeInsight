#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    vector<int> d(n);
    rep(i, n) cin >> d[i];
    ll tot = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            tot += d[i]*d[j];
        }
    }
    cout << tot << endl;
    return 0;
}