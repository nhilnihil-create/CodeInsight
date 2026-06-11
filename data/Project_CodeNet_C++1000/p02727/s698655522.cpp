#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;
const ll LINF = 1001001001001001;
const int MOD = 1000000007;

template <typename T>
void print(const T &v);

int main()
{
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    vector<ll> p(a), q(b), r(c);
    for (int i = 0; i < a; i++)
    {
        cin >> p[i];
    }
    for (int i = 0; i < b; i++)
    {
        cin >> q[i];
    }
    for (int i = 0; i < c; i++)
    {
        cin >> r[i];
    }
    sort(p.begin(), p.end());
    reverse(p.begin(), p.end());
    sort(q.begin(), q.end());
    reverse(q.begin(), q.end());
    sort(r.begin(), r.end());
    reverse(r.begin(), r.end());
    vector<ll> picks;
    for (int i = 0; i < x; i++)
    {
        picks.push_back(p[i]);
    }
    for (int i = 0; i < y; i++)
    {
        picks.push_back(q[i]);
    }
    sort(picks.begin(), picks.end());
    for (int i = 0; i < c && i < x + y; i++)
    {
        picks[i] = max(picks[i], r[i]);
    }
    ll ans = 0;
    for (int i = 0; i < x + y; i++)
    {
        ans += picks[i];
    }
    cout << ans << endl;
    return 0;
}

// Use For Debug
template <typename T>
void print(T const &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << ' ';
        cout << v[i];
    }
    cout << endl;
};