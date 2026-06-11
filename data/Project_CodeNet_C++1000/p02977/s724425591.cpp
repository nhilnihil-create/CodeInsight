#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
using namespace std;
#define prev prev228
#define all(x) (x).begin(), (x).end()

vector<pair<int, int> > edges;

int main()
{
    int n;
    cin >> n;
    if (__builtin_popcount(n) == 1)
    {
        cout << "No";
        return 0;
    }
    cout << "Yes\n";
    if (n % 4 == 3)
    {
        edges.push_back({1, 3});
        edges.push_back({3, 2});
        edges.push_back({2, n + 1});
        edges.push_back({n + 1, n + 3});
        edges.push_back({n + 3, n + 2});
        int lst = n + 2;
        for (int i = 4; i + 3 <= n; i += 4)
        {
            edges.push_back({lst, i});
            edges.push_back({i, i + 1});
            edges.push_back({i + 1, i + 2});
            edges.push_back({i + 2, i + 3});
            edges.push_back({i + 3, n + i});
            edges.push_back({n + i, n + i + 1});
            edges.push_back({n + i + 1, n + i + 2});
            edges.push_back({n + i + 2, n + i + 3});
            lst = n + i + 3;
        }
    }
    else
    {
        edges.push_back({1, 3});
        edges.push_back({3, 2});
        edges.push_back({2, n + 1});
        edges.push_back({n + 1, n + 3});
        edges.push_back({n + 3, n + 2});
        int t = 0;
        int N = (n / 4) * 4;
        for (int k = 0; k < 30; k++)
        {
            if (N & (1 << k))
            {
                t = (1 << k);
                break;
            }
        }
        int v1 = t;
        int v2 = N ^ t;
        int lst = -1;
        for (int i = 4; i + 3 <= n; i += 4)
        {
            if (i == v2) lst = v1;
            if (lst != -1) edges.push_back({lst, i});
            edges.push_back({i, i + 1});
            edges.push_back({i + 1, i + 2});
            edges.push_back({i + 2, i + 3});
            edges.push_back({i + 3, n + i});
            edges.push_back({n + i, n + i + 1});
            edges.push_back({n + i + 1, n + i + 2});
            edges.push_back({n + i + 2, n + i + 3});
            lst = n + i + 3;
        }
        edges.push_back({v1, N});
        edges.push_back({v2, n + N});
        edges.push_back({N, 1});
        if (n % 4 >= 1)
        {
            edges.push_back({N + 1 + n, N});
            edges.push_back({1, N + 1});
        }
        if (n % 4 >= 2)
        {
            edges.push_back({N + 2 + n, N});
            edges.push_back({3, N + 2});
        }
    }
    if (n == 5)
    {
        edges.clear();
        edges.push_back({1, 2});
        edges.push_back({3, 2});
        edges.push_back({3, n + 1});
        edges.push_back({n + 1, n + 2});
        edges.push_back({n + 3, n + 2});
        edges.push_back({4, 1});
        edges.push_back({5, 4});
        edges.push_back({5 + n, 1});
        edges.push_back({5 + n, 4 + n});
    }
    if (n == 6)
    {
        edges.clear();
        edges.push_back({1, 2});
        edges.push_back({3, 2});
        edges.push_back({3, n + 1});
        edges.push_back({n + 1, n + 2});
        edges.push_back({n + 3, n + 2});
        edges.push_back({4, 1});
        edges.push_back({5, 4});
        edges.push_back({5 + n, 1});
        edges.push_back({5 + n, 4 + n});
        edges.push_back({6, 2});
        edges.push_back({n + 6, 5 + n});
    }
    if (n == 9)
    {
        edges.clear();
        edges.push_back({1, 2});
        edges.push_back({3, 2});
        edges.push_back({3, n + 1});
        edges.push_back({n + 1, n + 2});
        edges.push_back({n + 3, n + 2});
        int lst = n + 2;
        for (int i = 4; i + 3 <= 7; i += 4)
        {
            edges.push_back({lst, i});
            edges.push_back({i, i + 1});
            edges.push_back({i + 1, i + 2});
            edges.push_back({i + 2, i + 3});
            edges.push_back({i + 3, n + i});
            edges.push_back({n + i, n + i + 1});
            edges.push_back({n + i + 1, n + i + 2});
            edges.push_back({n + i + 2, n + i + 3});
            lst = n + i + 3;
        }
        edges.push_back({9, 1});
        edges.push_back({8, 9});
        edges.push_back({1, n + 8});
        edges.push_back({n + 9, n + 8});
    }
    if (n == 10)
    {
        edges.clear();
        edges.push_back({1, 2});
        edges.push_back({3, 2});
        edges.push_back({3, n + 1});
        edges.push_back({n + 1, n + 2});
        edges.push_back({n + 3, n + 2});
        int lst = n + 2;
        for (int i = 4; i + 3 <= 7; i += 4)
        {
            edges.push_back({lst, i});
            edges.push_back({i, i + 1});
            edges.push_back({i + 1, i + 2});
            edges.push_back({i + 2, i + 3});
            edges.push_back({i + 3, n + i});
            edges.push_back({n + i, n + i + 1});
            edges.push_back({n + i + 1, n + i + 2});
            edges.push_back({n + i + 2, n + i + 3});
            lst = n + i + 3;
        }
        edges.push_back({9, 1});
        edges.push_back({8, 9});
        edges.push_back({1, n + 8});
        edges.push_back({n + 9, n + 8});
        edges.push_back({10, 9});
        edges.push_back({n + 10, 2});
    }
    for (auto e : edges) cout << e.first << " " << e.second << endl;
}
