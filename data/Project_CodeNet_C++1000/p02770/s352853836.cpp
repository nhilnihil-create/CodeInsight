#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 5100;

int K, Q;
ll d[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> K >> Q;
    for (int i = 0; i < K; i++)
        cin >> d[i];

    for (int i = 0; i < Q; i++)
    {
        int n;
        ll x, m;
        cin >> n >> x >> m;

        ll y = x;
        for (int j = 0; j < K; j++)
        {
            ll nv = (n - 1) / K;
            if ((n - 1) % K > j) nv++;

            ll cv = d[j] % m;
            if (cv == 0) cv = m;
            y += nv * (ll) cv;
        }

        cout << (n - 1) - (y / m - x / m) << "\n";
    }
}