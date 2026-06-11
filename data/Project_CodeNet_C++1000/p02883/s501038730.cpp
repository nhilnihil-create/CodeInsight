#include <bits/stdc++.h>
#include <boost/range/irange.hpp>
using namespace std;
using boost::irange;

int main() {
    int64_t N, K;
    cin >> N >> K;
    vector<int64_t> A(N), F(N);
    for (auto& v : A) cin >> v;
    for (auto& v : F) cin >> v;
    sort(begin(A), end(A));
    sort(begin(F), end(F), greater<int64_t>());
    auto r = boost::irange(0l, A[N-1] * F[0]);
    cout << *partition_point(begin(r), end(r), [&](int64_t x) {
        for (int64_t i = 0, k = 0; i < N; ++i) {
            k += max(0l, A[i] - x / F[i]);
            if (k > K) return true;
        }
        return false;
    }) << '\n';
}
