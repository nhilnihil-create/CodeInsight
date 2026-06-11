#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int d = 0;
    for (auto &v : a) {
        cin >> v;
        d = __gcd(d, v);
    }
    if (d != 1) {
        cout << "not coprime\n";
        return 0;
    }
    
    int N = int(1e6) + 1;
    vector<int> div(N);
    for (int i = 0; i < N; ++i) div[i] = i;
    
    for (int i = 2; i < N; ++i) if (div[i] == i) {
        for (int j = i + i; j < N; j += i)
            if (div[j] == j) div[j] = i;
    }

    vector<int> cnt(N, 0);
    for (auto &v : a) {
        int t = v;
        while (t > 1) {
            int f = div[t];
            ++cnt[f];
            while (t % f == 0) t /= f;
        }
    }

    for (int i = 2; i < N; ++i) if (cnt[i] > 1) {
        cout << "setwise coprime\n";
        return 0;
    }
    cout << "pairwise coprime\n";
    return 0;
}