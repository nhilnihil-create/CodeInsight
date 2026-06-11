#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
using ll = long long;

const int M = 1000005;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    rep(i,n) cin >> a[i];

    vector<int> count(M);

    for (int x : a) {
        if (count[x] != 0) {
            count[x]++;
            continue;
        }
        for (int j = x; j < M; j += x) {
            count[j]++;
        }
    }

    int ans = 0;
    rep(i,n) {
        if (count[a[i]] == 1) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}