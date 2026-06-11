#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP0(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define RREP0(i, n) for (int i = (n)-1; i >= 0; --i)
#define REP1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define RREP1(i, n) for (int i = (n); i >= 1; --i)
#define pow10(n) int(1e##n + n)

typedef long long LL;
typedef pair<int, int> P;

const int INTINF = int(1e9) + 1;
const LL LLINF = LL(1e18) + 1;
long double eps = 1.0E-14;

void solve()
{
    int N;
    cin >> N;
    vector<LL> A(N);
    REP0 (i, N)
    {
        cin >> A[i];
    }
    sort(A.begin(), A.end(), [](LL a, LL b) { return a > b; });
    vector<pair<LL, LL>> S;
    for (int i = 1; i < N - 1; i++)
    {
        if (A[i] >= 0)
        {
            S.push_back(make_pair(A[N - 1], A[i]));
            A[N - 1] -= A[i];
        }
        else
        {
            S.push_back(make_pair(A[0], A[i]));
            A[0] -= A[i];
        }
    }
    S.push_back(make_pair(A[0], A[N - 1]));
    A[0] -= A[N - 1];
    std::cout << A[0] << endl;
    for (auto p : S)
    {
        std::cout << p.first << " " << p.second << endl;
    }
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(20);
    solve();
    return 0;
}
