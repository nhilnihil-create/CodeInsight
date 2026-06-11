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
    map<int, int> mp;
    akari<int> as(n);
    for (int i = 0; i < n; i++)
    {
        cin >> as[i];
        mp[as[i]]++;
    }
    //sort(as.begin(), as.end());
    if (mp[1])
    {
        if (mp[1] == 1)
        {
            cout << 1 << endl;
            return;
        }
        else
        {
            cout << 0 << endl;
            return;
        }
    }
    int ans = 0;
    for (int a : as)
    {
        bool ok = mp[a] == 1;
        for (int f = 2; f * f <= a; f++)
        {
            if (a % f == 0 && (mp[a / f] || mp[f]))
            {
                ok = 0;
            }
        }
        ans += ok;
    }
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}
