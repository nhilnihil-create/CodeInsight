// ABC175DW.cpp
//#include "pch.h"
#include <iostream>
#include <vector>
#include <set>
#include <algorithm> // max
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
int main()
{
    ll n, k;
    cin >> n >> k;
    vector<ll>p(n);
    rep(i, n) {
        cin >> p.at(i);
        p.at(i)--;
    }
    vector<ll>c(n);
    rep(i, n) {
        cin >> c.at(i);
    }
    vector<vector<ll>> s(n); // 各マスからスタートする
    vector<ll>sum(n);
    rep(i, n) {
        ll st = i; // 各ループのスタート位置
        ll now = st;
        s.at(i).push_back(st);
        sum.at(i) = c.at(st);
        while (st != p.at(now)) {
            s.at(i).push_back(p.at(now));
            sum.at(i) += c.at(p.at(now)); // 各ループの小計　負なら繰り返さないほうが良い
            now = p.at(now);
        }
    }
    vector<ll> cnt(n,-1);
    vector<ll> period(n);
    vector<ll>mx(n,-1e18);
    ll ans=-1e18;
    rep(i, n) { // 各マスから初めてみる
        period.at(i) = s.at(i).size(); // それぞれの周期の長さ
        ll sums = 0;
        rep(a, period.at(i)) {
            if (a + 1 > k) break;
            sums += c.at(s.at(i).at(a));
            ll rpt_times_sum = 0;
            ll rpt_times = 0;
            if (sum.at(i) > 0) {
                rpt_times = (k - a - 1) / period.at(i); // sumが正の時の繰り返しの回数
                rpt_times_sum = rpt_times * sum.at(i); // 繰り返した部分の合計
            }
            ans = max(ans, sums + rpt_times_sum);
        }
    }
        cout << ans << endl;
        return 0;
    }
