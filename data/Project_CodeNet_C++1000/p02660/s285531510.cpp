#include <bits/stdc++.h>
using namespace std;

vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long i = 2; i*i <= N; i++) {
        if (N%i != 0) continue;
        long long ex = 0;

        while (N%i == 0) {
            ex++;
            N /= i;
        }
        res.push_back({i, ex});
    }

    if (N != 1) res.push_back({N, 1});
    return res;
}

int main(int argc, char const *argv[]) {
    long long n;
    cin >> n;
    vector<pair<long long, long long> > res = prime_factorize(n);

    long long ans = 0;
    for (auto p : res) {
        long long ex = p.second;
        for (long long i = 1; i <= ex; i++) {
            ans++;
            ex -= i;
        }
    }
    cout << ans << endl;
    return 0;
}
