//#define _GLIBCXX_DEBUG
#include "bits/stdc++.h"

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
    int m = 1 << n;
    aoi<int> pq;
    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        pq.push(a);
    }
    akari<int> used = {pq.top()};
    pq.pop();
    for (int i = 0; i < n; i++)
    {
        akari<int> nused(used);
        aoi<int> npq;
        for (int j = 0; j < 1 << i; j++)
        {
            bool ok = 0;
            while (!pq.empty())
            {
                int b = pq.top();
                pq.pop();
                if (used[j] > b)
                {
                    ok = 1;
                    nused.push_back(b);
                    break;
                }
                else
                {
                    npq.push(b);
                }
            }
            if (!ok)
            {
                cout << "No" << endl;
                return;
            }
        }
        while (!pq.empty())
        {
            npq.push(pq.top());
            pq.pop();
        }
        swap(pq, npq);
        swap(used, nused);
        sort(used.rbegin(), used.rend());
    }
    cout << "Yes" << endl;
}

int main()
{
    solve();
    return 0;
}
