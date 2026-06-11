#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll A, B, M;
    vector<ll> a;
    vector<ll> b;
    ll min_a = 1000000;
    ll min_b = 1000000;

    cin >> A >> B >> M;
    for (int i = 0; i < A; ++i)
    {
        ll temp;
        cin >> temp;
        a.push_back(temp);
        min_a = min(min_a, temp);
    }
    for (int i = 0; i < B; ++i)
    {
        ll temp;
        cin >> temp;
        b.push_back(temp);
        min_b = min(min_b, temp);
    }
    ll x, y, c;
    ll ans = 300000;

    for (int i = 0; i < M; ++i)
    {
        cin >> x >> y >> c;
        ll temp = a[x - 1] + b[y - 1] - c;
        ans = min(temp, ans);
    }

    cout << min(ans, min_a + min_b) << endl;
}
