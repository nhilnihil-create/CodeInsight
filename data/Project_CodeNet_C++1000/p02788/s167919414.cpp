#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i, n) for (int i = 0; i < (n); ++i)
template <typename T>
struct BIT
{
    int n;            // 要素数
    vector<T> bit[2]; // データの格納先
    BIT(int n_) { init(n_); }
    void init(int n_)
    {
        n = n_ + 1;
        for (int p = 0; p < 2; p++)
            bit[p].assign(n, 0);
    }
    void add_sub(int p, int i, T x)
    {
        for (int idx = i; idx < n; idx += (idx & -idx))
        {
            bit[p][idx] += x;
        }
    }
    void add(int l, int r, T x)
    { // [l,r) に加算
        add_sub(0, l, -x * (l - 1));
        add_sub(0, r, x * (r - 1));
        add_sub(1, l, x);
        add_sub(1, r, -x);
    }
    T sum_sub(int p, int i)
    {
        T s(0);
        for (int idx = i; idx > 0; idx -= (idx & -idx))
        {
            s += bit[p][idx];
        }
        return s;
    }
    T sum(int i) { return sum_sub(0, i) + sum_sub(1, i) * i; }
};

ll inf = (1 << 30);
int main()
{
    int n;
    ll D, A;
    cin >> n >> D >> A;
    ll x,h;
    pair<ll, ll> xh[n + 1];
    rep(i, n)
    {
        cin >> x >> h;
        xh[i] = make_pair(x, h);
    }
    xh[n] = make_pair(inf, 0);
    sort(xh, xh + n + 1);
    // rep(i,n){
    //     cout << xh[i+1].first << " "<<xh[i+1].second << endl;
    // }
    // cout << inf << endl;

    BIT<ll> bit(n);
    rep(i, n)
    {
        bit.add(i + 1, i + 2, xh[i].second);
    }
    // bit.add(2, 4, -4);
    // rep(i,n){
    //     int now_hp = bit.sum(i + 1) - bit.sum(i);
    //     printf("%dは %d hp ある\n", i, now_hp);
    // }
    // printf("----\n");
    ll ans = 0;
    rep(i, n)
    {
        ll now_hp = bit.sum(i + 1) - bit.sum(i);
        if (now_hp <= 0)
            continue;
        x = xh[i].first;
        pair<ll, ll>  *x_2d = upper_bound(xh, xh + n + 1, make_pair(x + 2 * D, inf));
        // P *x_2d = upper_bound(xh, xh + n + 1, make_pair(x + 2*D, INF));
        ll next_idx = x_2d - xh;
        ll count = (A + (now_hp - 1)) / A;
        ans += count;
        ll damage = count * A;
        // printf("%dは %d hp ある\n", i+1, now_hp);
        // printf("[%d から　%d) に %d回 %dダメージ\n", i+1, next_idx+1, (a+(now_hp - 1))/a, damage);
        bit.add(i + 1, next_idx + 1, -damage);
    }
    cout << ans << endl;

    return 0;
}