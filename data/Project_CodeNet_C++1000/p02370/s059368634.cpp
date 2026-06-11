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
    int n, m;
    cin >> n >> m;
    yukari<int> g(n);
    akari<int> e(n);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        e[v]++;
    }
    queue<int> q;
    for (int s = 0; s < n; s++)
    {
        if (!e[s])
        {
            q.push(s);
        }
    }

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int nv : g[v])
        {
            e[nv]--;
            if (!e[nv])
            {
                q.push(nv);
            }
        }
        cout << v << '\n';
    }
}

int main()
{
    solve();
    return 0;
}

