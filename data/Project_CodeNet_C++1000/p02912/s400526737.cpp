// #define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

void solve()
{
    int n, m;
    cin >> n >> m;
    priority_queue<int> pq;
    rep(i, n)
    {
        int a;
        cin >> a;
        pq.push(a);
    }
    rep(i, m)
    {
        int mx = pq.top();
        pq.pop();
        mx /= 2;
        pq.push(mx);
    }
    ll ans = 0;
    while (pq.size())
    {
        int x = pq.top();
        pq.pop();
        ans += x;
    }
    cout << ans << endl;
}

int main()
{
    solve();
    return 0;
}