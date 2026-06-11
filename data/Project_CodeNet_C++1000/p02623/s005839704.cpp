#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> a(1, 0);
vector<ll> b(1, 0);
vector<ll> cum(1, 0);

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        int A;
        cin >> A;
        a.push_back(a[i] + A);
    }
    for (int i = 0; i < m; i++)
    {
        int B;
        cin >> B;
        b.push_back(b[i] + B);
    }

    int ans = 0;
    int j = m;

    for (int i = 0; i < n + 1; i++)
    {
        if (a[i] > k) break;

        while (b[j] > k - a[i] && j > 0)
        {
            j--;
        }

        ans = max(ans, i + j);
    }

    cout << ans << endl;

    return 0;
}