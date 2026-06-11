//#define _GLIBCXX_DEBUG
#include "bits/stdc++.h"

using namespace std;

//------------------------------- Libraries --------------------------------//

//------------------------------- Type Names -------------------------------//

using i64 = int_fast64_t;

using seika = string;
//akari : 1D, yukari : 2D, maki : 3D vector
template <class kizuna>
using akari = vector<kizuna>;
template <class yuzuki>
using yukari = akari<akari<yuzuki>>;
template <class tsurumaki>
using maki = akari<yukari<tsurumaki>>;
//akane : ascending order, aoi : decending order
template <class kotonoha>
using akane = priority_queue<kotonoha, akari<kotonoha>, greater<kotonoha>>;
template <class kotonoha>
using aoi = priority_queue<kotonoha>;

//------------------------------- Dubug Functions ---------------------------//
inline void print()
{
    cout << endl;
}
template <typename First, typename... Rest>
void print(const First &first, const Rest &... rest)
{
    cout << first << ' ';
    print(rest...);
}
//------------------------------- Solver ------------------------------------//

void solve()
{
    int n, k;
    cin >> n >> k;
    akari<int> hs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> hs[i];
    }
    hs.push_back(0);
    yukari<i64> dp(n + 2, akari<i64>(k + 1, 1e15));
    dp[0][0] = 0;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= k; j++)
        {
            if (dp[i][j] == 1e15)
            {
                continue;
            }
            for (int x = 0; j + x <= k && i + x + 1 <= n + 1; x++)
            {
                int ni = i + x + 1;
                dp[ni][j + x] = min(dp[ni][j + x], dp[i][j] + max(0, hs[ni - 1] - (i ? hs[i - 1] : 0)));
            }
        }
    cout << *min_element(dp.back().begin(), dp.back().end()) << endl;
}

int main()
{
    solve();
    return 0;
}
