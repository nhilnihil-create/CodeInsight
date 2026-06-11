
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

    vector<int> d(n);
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }

    SortAsc(d);

    int c = n / 2;
    int res = d[c] - d[c - 1];

    cout << res << endl;
}