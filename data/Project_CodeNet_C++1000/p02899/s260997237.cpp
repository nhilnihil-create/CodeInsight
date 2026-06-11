
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
#define SortAsc(c) std::sort(c.begin(), c.end())
#define SortDesc(c) std::sort(c.rbegin(), c.rend())
int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        int n;
        cin >> n;
        a[i] = make_pair(n, i + 1);
    }

    SortAsc(a);

    for (int i = 0; i < n; i++)
    {
        auto p = a[i];
        if (i != 0)
        {
            cout << " ";
        }
        cout << p.second;
    }

    cout << endl;
}