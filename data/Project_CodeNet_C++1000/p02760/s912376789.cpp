#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, l, r) for (int i = (l); i < (r); i++)
#include <bits/stdc++.h>
//~ #include <atcoder/all>
using namespace std;
using ll = long long;
//~ using P = pair<int, int>;

vector<vector<int>> v =
    {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}};

int main()
{
    int a[9];
    rep(i, 9) cin >> a[i];

    int n;
    cin >> n;

    bool exist[9];
    rep(i, 9) exist[i] = false;

    while (n--)
    {
        int b;
        cin >> b;
        rep(i, 9) if (a[i] == b) exist[i] = true;
    }

    for (auto r : v)
    {
        bool yn = true;
        for (auto e : r)
        {
            if (exist[e] == false)
                yn = false;
        }
        if (yn == true)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}
