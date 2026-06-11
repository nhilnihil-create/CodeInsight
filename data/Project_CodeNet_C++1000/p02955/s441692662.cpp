#ifdef _MSC_VER
#include <__msvc_all_public_headers.hpp>
#undef min
#undef max
#else
#define NDEBUG
#include <bits/stdc++.h>
#endif

using namespace std;
using large = long long;

int N, K;
static vector<int> A;

static large solve() {
    auto divisor = set<int, greater<int>>();
    {
        auto Asum = accumulate(A.begin(), A.end(), 0LL);
        for (auto x = 1; x * x <= Asum; ++x) {
            if (Asum % x != 0)
                continue;
            divisor.insert(x);
            divisor.insert(Asum / x);
        }
    }
    auto rem1 = vector<int>(N + 1);
    auto rem2 = vector<int>(N + 1);
    for (auto d : divisor) {
        rem1.clear();
        for (auto i = 0; i < N; ++i) {
            auto tmp = A[i] % d;
            if (tmp < 0)
                tmp += d;
            if (tmp != 0) {
                rem1.push_back(tmp);
            }
        }
        if (rem1.empty())
            return d;

        sort(rem1.begin(), rem1.end());
        rem2.clear();
        auto rightsum = 0LL;
        for (auto i = 0; i < rem1.size(); ++i) {
            rightsum += (d - rem1[i]);
            rem2.push_back(d - rem1[i]);
        }

        auto leftsum = 0LL;
        for (auto leftcnt = 0; leftcnt < rem1.size(); ++leftcnt) {
            leftsum += rem1[leftcnt];
            rightsum -= rem2[leftcnt];
            if (leftsum == rightsum && leftsum <= K)
                return d;
        }
    }

    return 1;
}

int main() {
    cin >> N >> K;
    A.resize(N);
    for (auto& Ai : A)
        cin >> Ai;
    sort(A.begin(), A.end());
    cout << solve() << endl;
    return 0;
}
