#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> w(n);
    int sum = 0;
    rep(i, n) {
        cin >> w[i];
        sum += w[i];
    }

    int mi = 1000000;
    int si = 0;
    rep(i, n) {
        si += w[i];
        mi = min(mi, abs(sum - si * 2));
    }

    cout << mi << endl;

}