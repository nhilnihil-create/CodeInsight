#include<bits/stdc++.h>
using namespace std;

int main() {
    cout.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<int> values(N);
    for (int& x : values) cin >> x;
    if (N == 1) {
        cout << "1\n";
    }
    else {
        sort(values.begin(), values.end());
        const int M = 2 * values.back();
        vector<int> freq(2*M+2);
        for (int X : values) {
            if (freq[X] > 0) {
                ++freq[X];
                continue;
            }
            ++freq[X];
            for (int p = 2*X; p <= 2*M; p += X)
                ++freq[p];
        }
        int res = 0;
        for (int X : values) {
            if (freq[X] != 1) continue;
            ++res;
        }
        cout << res << '\n';
    }
}
