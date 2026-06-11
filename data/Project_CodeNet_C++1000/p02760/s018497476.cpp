#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
#define forn(i, n) for (ll i = 0; i < n; i++)
#define forn1(i, n) for (ll i = 1; i <= n; i++)
#define EPS 1e-9
#define ff first
#define ss second
#define pb push_back
#define sortx(x) sort(x.begin(), x.end())
ll table[3][3];
ll pos[5][5];
int main()
{
    ios::sync_with_stdio(0);

    ll number;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> table[i][j];
        }
    }
    ll N, b, cnt = 0;
    cin >> N;
    while (N--)
    {
        cin >> b;
        forn(i, 3)
        {
            forn(j, 3)
            {
                if (table[i][j] == b)
                {
                    pos[i][j] = 1;
                    cnt++;
                }
            }
        }
    }
    if (cnt < 3)
    {
        cout << "No\n";
        return 0;
    }
    bool bingo = false;
    for (ll i = 0; i < 3; i++)
    {
        if (pos[i][0] && pos[i][1] && pos[i][2])
        {
            bingo = true;
        }
    }
    for (ll j = 0; j < 3; j++)
    {
        if (pos[0][j] && pos[1][j] && pos[2][j])
        {
            bingo = true;
        }
    }

    if (pos[0][0] && pos[1][1] && pos[2][2])
    {
        bingo = true;
    }
    if (pos[0][2] && pos[1][1] && pos[2][0])
    {
        bingo = true;
    }
    cout << (bingo ? "Yes\n" : "No\n");

    return 0;
}