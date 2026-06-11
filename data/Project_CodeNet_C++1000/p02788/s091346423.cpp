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
    ll d, a;
    cin >> n >> d >> a;
    map<ll, ll> monster;
    set<ll> query;
    map<ll, ll> detail;
    for (int i = 0; i < n; i++)
    {
        ll x, h;
        cin >> x >> h;
        monster[x - 1] = (h + a - 1) / a; // [座標][倒すのに必要な爆弾の個数]
    }

    ll ans = 0;
    ll cnt = 0;     // 現在の位置の爆弾の影響の個数
    ll before = -1; // 一つ前のモンスターの座標
    for (auto mon : monster)
    {
        int pos = mon.first;
        int hp = mon.second;
        if (!query.empty())
        {
            auto iter = query.lower_bound(before + 1);
            if (iter != query.end())
            {
                while (iter != query.end() && *iter <= pos)
                {
                    cnt -= detail[*iter];
                    ++iter;
                }
            }
        }
        if (hp - cnt > 0)
        {
            query.insert(pos + d + d + 1);
            detail[pos + d + d + 1] = hp - cnt;
            ans += hp - cnt;
            cnt += hp - cnt;
        }
        before = pos;
    }
    cout << ans << endl;
    return 0;
}
