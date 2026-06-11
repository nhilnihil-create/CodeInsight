#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) < (b) ? (b) : (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const unsigned long long MOD = 998244353;

int main()
{
    int n;
    cin >> n;
    vector<int> edge(n, 0);
    int max_length = 0;
    rep(i, n)
    {
        int tmp;
        cin >> tmp;
        if (i == 0 && tmp != 0)
        {
            cout << 0 << endl;
            return 0;
        }
        else if (i != 0 && tmp == 0)
        {
            cout << 0 << endl;
            return 0;
        }
        edge[tmp]++;
        max_length = max(max_length, tmp);
    }
    if (edge[0] != 1)
    {
        cout << 0 << endl;
        return 0;
    }
    ll out = 1;
    for (int i = 1; i <= max_length; i++)
    {
        rep(j, edge[i])
        {
            out = out * edge[i - 1] % MOD;
        }
    }
    cout << out << endl;

    return 0;
}