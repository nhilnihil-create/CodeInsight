#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
constexpr ld EPS = 1e-12;
constexpr int INF = numeric_limits<int>::max() / 2;
constexpr int MOD = 1e9 + 7;

template <typename T>
void printv(const vector<T> &v)
{
    int sz = v.size();
    for (int i = 0; i < sz; i++)
    {
        cout << v[i] << " \n"[i == sz - 1];
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    vector<int> enqueued(n, 0);
    priority_queue<P> que; // val, index
    for (int i = 0; i < n; i++)
    {
        // a[i] < b[i] && a[i-1] + a[i+1] < b[i] - a[i]
        if (a[i] >= b[i])
            continue;
        ll sum = b[(i + 1) % n] + b[(i + n - 1) % n];
        if (sum <= b[i] - a[i])
        {
            que.push(P(b[i], i));
            enqueued[i] = 1;
        }
    }
    ll ret = 0;
    while (!que.empty())
    {
        auto p = que.top();
        que.pop();
        int i = p.second;
        enqueued[i] = 0;
        int nxt = (i + 1) % n, pre = (i + n - 1) % n;
        ll sum = b[nxt] + b[pre];
        ll cnt = (b[i] - a[i]) / sum;
        ret += cnt;
        b[i] -= cnt * sum;
        if (!enqueued[nxt])
        {
            int nxt2 = (i + 2) % n;
            sum = b[nxt2] + b[i];
            if (sum <= b[nxt] - a[nxt])
            {
                que.push(P(b[nxt], nxt));
                enqueued[nxt] = 1;
            }
        }
        if (!enqueued[pre])
        {
            int pre2 = (i + n - 2) % n;
            sum = b[pre2] + b[i];
            if (sum <= b[pre] - a[pre])
            {
                que.push(P(b[pre], pre));
                enqueued[pre] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (b[i] != a[i])
        {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ret << endl;
}
