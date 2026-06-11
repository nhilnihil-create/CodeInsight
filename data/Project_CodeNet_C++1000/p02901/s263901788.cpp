#include <bits/stdc++.h>
#include <iostream>
#include <ctime>
using namespace std;
#define _LL long long
#define rep(i, n) for (_LL i = 0; i < (_LL)(n); i++)
#define vecrep(itr, v) for (auto itr = (v).begin(); itr != (v).end(); itr++)

int main()
{
    int n, m; cin >> n >> m;
    vector<pair<int, int>> key(m);
    rep(i, m)
    {
        int a, b; cin >> a >> b;
        int v = 0;
        rep(j, b)
        {
            int c; cin >> c;
            v |= (1 << (c - 1));
        }
        key[i].first = a;
        key[i].second = v;
    }
    priority_queue<pair<int, int>> q;
    int all = (1 << n) - 1;
    vector<int> cost(1 << n);
    rep(i, (1 << n)) cost[i] = (1 << 30);
    rep(i, m) 
    {
        q.emplace(-key[i].first, key[i].second);
        cost[key[i].second] = key[i].first;
    }
    while(!q.empty())
    {
        auto next = q.top();
        q.pop();
        int v = next.second;
        if( v == all )
        {
            cout << -next.first << endl;
            return 0;
        }
        if( cost[v] < -next.first ) continue;
        rep(i, m)
        {
            if( (v & key[i].second) == key[i].second ) continue;
            int nextv = (v | key[i].second);
            if( -next.first + key[i].first >= cost[nextv] ) continue;
            cost[nextv] = -next.first + key[i].first;
            q.emplace(-cost[nextv], nextv);
        }
    }
    cout << -1 << endl;
    return 0;    
}