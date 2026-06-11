#include <bits/stdc++.h>
using namespace std;
#define rep(i, N) for (long long i = 0; i < N; i++)
using ll = long long;

const string YES = "Yes";
const string NO = "No";

void solve(long long N, std::vector<long long> A, std::vector<long long> B) {
    vector<pair<ll, ll>> pairvec;
    rep(i, N) { pairvec.push_back(pair<ll, ll>(B[i], A[i])); }
    sort(pairvec.begin(), pairvec.end());
    ll t = 0;
    rep(i, N) {
        t += pairvec[i].second;
        if (t > pairvec[i].first) {
            cout << NO << endl;
            return;
        }
    }
    cout << YES << endl;
}

int main() {
    long long N;
    scanf("%lld", &N);
    std::vector<long long> A(N);
    std::vector<long long> B(N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
        scanf("%lld", &B[i]);
    }
    solve(N, std::move(A), std::move(B));
    return 0;
}
