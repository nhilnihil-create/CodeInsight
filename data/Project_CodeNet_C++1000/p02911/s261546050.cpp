#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main()
{
    ll n, k, q;
    cin >> n >> k >> q;
    ll p[n];
    rep(i, n) p[i] = k - q;
    rep(i, q)
    {
        ll a;
        cin >> a;
        p[a - 1]++;
        // rep(i, n)
        // {
        //     if (i + 1 == a)
        //         continue;
        //     p[i]--;
        // }
    }
    rep(i, n)
    {
        // cout << p[i] << endl;
        if (p[i] > 0)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}