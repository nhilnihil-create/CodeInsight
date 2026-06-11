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
    akari<int> as(n), bs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> as[i] >> bs[i];
    }
    sort(as.begin(), as.end());
    sort(bs.begin(), bs.end());
    int ans = 0;
    if (n & 1)
    {
        ans = bs[n / 2] - as[n / 2] + 1;
    }
    else
    {
        int m1 = as[n / 2] + as[n / 2 - 1];
        int m2 = bs[n / 2] + bs[n / 2 - 1];
        if (m1 & 1)
        {
            ans--;
        }
        if (m2 & 1)
        {
            ans++;
        }
        m1 >>= 1;
        m2 >>= 1;
        ans += (m2 - m1) * 2 + 1;
        //print(m1, m2);
    }
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}
