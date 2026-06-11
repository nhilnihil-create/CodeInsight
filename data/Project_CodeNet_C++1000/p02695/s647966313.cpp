#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, start, n) for (ll i = (ll)(start); i < (ll)(n); ++i)
static const ll INFTY = 1L << 62L;
ll d_max(vector<ll> A, ll *a, ll *b, ll *c, ll *d, ll q)
{
    ll ans = 0;
    rep(i, 0, q)
    {
        if (a[i] - 1 < A.size() && b[i] - 1 < A.size())
        {
            if (A[b[i] - 1] - A[a[i] - 1] == c[i])
                ans += d[i];
        }
    }
    return ans;
}
ll solver(ll *a, ll *b, ll *c, ll *d, ll n, ll m, ll q)
{

    queue<vector<ll>> que;
    rep(i, 1, m + 1) que.push(vector<ll>(1, i));
    ll ans = 0;
    while (!que.empty())
    {
        vector<ll> A = que.front();
        ans = max(ans, d_max(A, a, b, c, d, q));
        que.pop();
        ll tmp = A.back();
        if (A.size() < n)
        {
            while (tmp <= m)
            {
                A.push_back(tmp);
                que.push(A);
                A.pop_back();
                ++tmp;
            }
        }
    }
    return ans;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, m, q;
    cin >> n >> m >> q;
    ll a[q], b[q], c[q], d[q];
    rep(i, 0, q)
    {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    cout << solver(a, b, c, d, n, m, q) << endl;
}