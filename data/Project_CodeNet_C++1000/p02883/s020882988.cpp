#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;
const ll LINF = 1LL << 60;

template <typename T>
void print(const T &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << ' ';
        cout << v[i];
    }
    cout << endl;
}

int main()
{
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n), f(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> f[i];
    }
    sort(a.begin(), a.end());
    sort(f.begin(), f.end());
    reverse(f.begin(), f.end());

    ll left = -1, right = (1000000LL * 1000000LL) + 1;
    while (right - left > 1)
    {
        ll mid = (left + right) / 2;
        ll use = 0;
        for (int i = 0; i < n; i++)
        {
            // a[i]を減らして対応できるかを確認
            if (a[i] * f[i] <= mid)
            {
                continue;
            }
            ll boarder = mid / f[i];
            use += a[i] - boarder;
        }
        if (use <= k)
        {
            right = mid;
        }
        else
        {
            left = mid;
        }
        // cout << "left:" << left << ", right:" << right << endl;
    }
    cout << right << endl;
    return 0;
}
