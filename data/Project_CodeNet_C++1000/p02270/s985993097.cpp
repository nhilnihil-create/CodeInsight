#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int INF = INT_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> w(n);
    for(int i = 0; i < n; ++i) cin >> w[i];

    int ng = 0, ok = 100000 * 10000, mid, k_nec, wt;
    while(ok - ng != 1) {
        mid = (ok + ng) / 2;
        k_nec = 1;
        wt = 0;
        for(int wi: w) {
            if(wi > mid) {
                k_nec = INF;
                break;
            }
            else if(wt + wi <= mid) wt += wi;
            else {
                wt = wi;
                k_nec++;
            }
        }
        if(k_nec <= k) ok = mid;
        else ng = mid;
    }

    printf("%d\n", ok);

    return 0;
}
