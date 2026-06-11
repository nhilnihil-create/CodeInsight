#include <bits/stdc++.h>
using namespace std;

vector<long long> rbd(vector<long long> mat) {
    int n = mat.size();
    int rk = 0;
    for (int i = 60; i >= 0; i--) {
        bool exist = false;
        for (int j = rk; j < n; j++) {
            if (mat[j] >> i & 1) {
                exist = true;
                swap(mat[rk], mat[j]);
                break;
            }
        }
        if (exist) {
            for (int j = 0; j < n; j++) {
                if (j != rk && mat[j] >> i & 1) {
                    mat[j] ^= mat[rk];
                }
            }
            rk++;
        }
    }
    return mat;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    long long all = 0;
    vector<long long> as(n);
    for (int i = 0; i < n; i++) cin >> as[i];

    vector<int> cnt(60);
    for (int i = 0; i < n; i++) {
        all ^= as[i];
        for (int j = 0; j < 60; j++) {
            if (as[i] >> j & 1) cnt[j]++;
        }
    }
    long long ans = 0;
    for (int i = 0; i < 60; i++) {
        if (cnt[i] & 1) {
            ans += 1LL << i;
            for (int j = 0; j < n; j++) {
                if (as[j] >> i & 1) {
                    as[j] ^= 1LL << i;
                }
            }
        }
    }
    long long a = 0;
    auto bs = rbd(as);
    for (auto &b : bs) {
        a ^= b;
    }
    cout << a + (all ^ a) << endl;
}
