#include <bits/stdc++.h>
#include <iostream>
#include <ctime>
using namespace std;
#define _LL long long
#define rep(i, n) for (_LL i = 0; i < (_LL)(n); i++)
#define vecrep(itr, v) for (auto itr = (v).begin(); itr != (v).end(); itr++)

int main()
{
    _LL n, d, a;
    cin >> n >> d >> a;
    vector<_LL> x(n); vector<_LL> h(n);   
    vector<pair<_LL, _LL>> enemy(n); 
    rep(i, n)
    {
        _LL x, h;
        cin >> x >> h;
        h = (h - 1) / a + 1;
        enemy[i].first = x;
        enemy[i].second = h;
    }

    queue<pair<_LL, _LL>> q;
    sort(enemy.begin(), enemy.end());
    _LL damage = 0;
    _LL ans = 0;
    rep(i, n)
    {
        while( !q.empty() )
        {
            if( q.front().first >= enemy[i].first ) break;
            damage -= q.front().second;
            q.pop();
        }
        _LL hp = enemy[i].second - damage;
        if( hp > 0 )
        {
            damage += hp;
            ans += hp;
            q.push(make_pair(enemy[i].first + d + d, hp));
        }
    }
    cout << ans;
}