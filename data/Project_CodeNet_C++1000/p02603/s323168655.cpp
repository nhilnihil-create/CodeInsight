#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;
const int N = 1e6 + 34;

int main()
{
    ll c = 1000;
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i + 1 < n; i++)
    {
        if (a[i] < a[i + 1])
        {
            ll cnt = c / a[i];
            c -= cnt * a[i];
            c += cnt * a[i + 1];
        }
    }
    cout << c;
}
