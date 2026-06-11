#include "bits/stdc++.h"

using namespace std;

long long myatoll(char c) {
    return (long long)atoi(&c);
}

long long P_is_not_2_5(long long N, long long P, const string& S) {
    map<long long, long long> residual;
    residual.insert(make_pair(0LL, 1LL));
    long long pow10 = 1;
    long long curr = 0LL;
    for (long long i = N - 1; i >= 0; --i) {
        //int s = atoi(S.substr(i, 1).c_str());
        //int m = (s * pow10 + curr) % P;
        //if (residual.count(m) == 0) {
        //    residual.insert(make_pair(m, 0LL));
        //}
        //residual[m] += 1;
        //curr = m;
        long long x = (curr + pow10 * (long long)atoi(S.substr(i, 1).c_str())) % P;
        if (residual.count(x) == 0) {
            residual.insert(make_pair(x, 1LL));
        }
        else {
            residual[x] += 1;
        }
        curr = x;
        pow10 *= 10;
        pow10 %= P;
    }
    long long ans = 0;
    for (auto it : residual) {
        long long n = it.second;
        if (n >= 2) {
            ans += n * (n - 1) / 2;
        }
    }
    return ans;
}

long long P_is_2_or_5(long long N, long long P, const string& S) {
    long long ans = 0LL;
    for (long long i = 0; i < N; ++i) {
        long long c = myatoll(S[i]);
        if (c % P == 0) {
            ans += i + 1;
        }
    }
    return ans;
}

void Main() {
    long long N, P;
    cin >> N >> P;
    string S;
    cin >> S;

    long long ans = 0LL;
    if (P == 2LL || P == 5LL) {
        ans = P_is_2_or_5(N, P, S);
    }
    else {
        ans = P_is_not_2_5(N, P, S);
    }
    cout << ans << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
