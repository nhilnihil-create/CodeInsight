#include <bits/stdc++.h>


using namespace std;


long long comb2(long long x) {
    if (x < 2)
        return 0;
    return (x * (x - 1)) / 2;
}


int main() {
    long long N, P;
    string S;
    cin >> N >> P;
    cin >> S;

    if (P == 2 || P == 5) {
        long long ans = 0;
        for (long long i = S.length() - 1; i >= 0; i--) {
            if ((S[i] - '0') % P == 0) {
                ans += (i + 1);
            }
        }
        cout << ans << endl;
        return 0;
    }

    vector<long long> r_cnt(P, 0);
    r_cnt[0]++;
    long long r = 0;
    long long base = 1;
    for (long long i = S.length() - 1; i >= 0; i--) {
        r += (S[i] - '0') * base;
        r %= P;
        r_cnt[r]++;
        base = (base * 10) % P;
    }

    long long ans = 0;
    for (auto c : r_cnt) {
        ans += comb2(c);
    }
    cout << ans << endl;
}
