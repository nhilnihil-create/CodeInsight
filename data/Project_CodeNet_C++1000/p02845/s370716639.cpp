#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP0(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define RREP0(i, n) for (int i = (n)-1; i >= 0; --i)
#define REP1(i, n) for (int i = 1, i##_len = (n); i <= i##_len; ++i)
#define RREP1(i, n) for (int i = (n); i >= 1; --i)

typedef long long LL;
typedef pair<int, int> pii;

const int INTINF = int(1e9) + 1;
const LL LLINF = LL(1e18) + 1;
long double eps = 1.0E-14;
#define pow10(n) int(1e##n + n)
const LL mod = LL(1e9) + 7;

void solve()
{
    int N;
    cin >> N;
    int n1 = 0, n2 = 0, n3 = 0;  // n1 <= n2 <=n3

    LL ans = 1;
    REP0 (i, N)
    {
        int A;
        cin >> A;
        int f = (A == n3) + (A == n2) + (A == n1);
        ans *= f;
        ans %= mod;
        if (A == n3)
        {
            n3++;
        }
        else if (A == n2)
        {
            n2++;
        }
        else if (A == n1)
        {
            n1++;
        }
        else
        {
            std::cout << 0 << endl;
            return;
        }
    }
    std::cout << ans << endl;
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(20);
    solve();
    return 0;
}
