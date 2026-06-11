//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

using namespace std;

//------------------------------- Type Names -------------------------------//

using i64 = int_fast64_t;

using seika = string;
//{akari : 1D, yukari : 2D, maki : 3D} vector
template <class kizuna>
using akari = vector<kizuna>;
template <class yuzuki>
using yukari = akari<akari<yuzuki>>;
template <class tsurumaki>
using maki = akari<yukari<tsurumaki>>;
//{akane : ascending order, aoi : decending order} priority queue
template <class kotonoha>
using akane = priority_queue<kotonoha, akari<kotonoha>, greater<kotonoha>>;
template <class kotonoha>
using aoi = priority_queue<kotonoha>;

//------------------------------- Libraries ---------------------------------//

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
    int n;
    cin >> n;
    akari<int> as(n);
    akari<pair<i64, int>> ps(n);
    for (int i = 0; i < n; i++)
    {
        cin >> as[i];
        ps[i] = {as[i], i};
    }
    sort(ps.rbegin(), ps.rend());
    akari<i64> dp(n, -1e18);
    dp[0] = 0;
    for (int i = 0; i < n; i++)
    {
        auto new_dp(dp);
        int k = ps[i].second;
        i64 a = ps[i].first;
        for (int j = 0; j < n; j++)
        {
            if (j)
            {
                new_dp[j] = max(new_dp[j], dp[j - 1] + abs(j - k - 1) * a);
            }
            new_dp[j] = max(new_dp[j], dp[j] + abs(n - 1 - i + j - k) * a);
        }
        swap(dp, new_dp);
    }
    cout << *max_element(dp.begin(), dp.end()) << endl;
}

int main()
{
    solve();
    return 0;
}
