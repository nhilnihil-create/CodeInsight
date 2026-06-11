#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
using ll = long long;

int main() {
    int k;
    cin >> k;

    vector<ll> v;
    for (int i = 1; i <= 9; ++i) {
        v.push_back(i);
    }

    while (1) {
        if (k <= v.size()) {
            cout << v[k-1] << endl;
            return 0;
        }
        k -= v.size();
        vector<ll> old;
        swap(old, v);

        for (ll o : old) {
            int t = o % 10;
            for (int i = -1; i <= 1; i++) {
                if ((t+i) < 0 || (t+i) > 9) {
                    continue;
                }
                v.push_back(o*10+(t+i));
            }
        }
    }
    return 0;
}