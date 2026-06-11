#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int main()
{
    int K, Q;
    cin >> K >> Q;
    vector<int> D(K);
    for (auto &x : D) cin >> x;

    while (Q--) {
        int N, X, M;
        cin >> N >> X >> M;
        N--;
        X %= M;

        vector<lint> add;
        for (auto d : D) {
            if (d) add.emplace_back((d - 1) % M + 1);
            else add.emplace_back(M);
        }
        __int128_t tot = accumulate(add.begin(), add.end(), 0LL);
        lint cycle = N / K;
        tot *= cycle;
        int rem = N % K;
        for (int i = 0; i < rem; i++) tot += add[i];
        tot += X;
        lint ret = N - tot / M;
        cout << ret << endl;
    }
}
