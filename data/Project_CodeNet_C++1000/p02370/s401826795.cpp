/*
    Author:zeke
    
    pass System Test!
    GET AC!!
*/
#include <iostream>
#include <queue>
#include <vector>
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <algorithm>
#include <functional>
#include <cmath>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <map>
#include <iomanip>
#include <math.h>
#include <utility>
#include <stack>
#include <bitset>
using ll = long long;
using ld = long double;
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define rep3(var, min, max) for (ll(var) = (min); (var) < (max); ++(var))
#define repi3(var, min, max) for (ll(var) = (max)-1; (var) + 1 > (min); --(var))
#define Mp(a, b) make_pair((a), (b))
#define F first
#define S second
#define Icin(s) \
    ll(s);      \
    cin >> (s);
#define Scin(s) \
    ll(s);      \
    cin >> (s);
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}
typedef pair<ll, ll> P;
typedef vector<ll> V;
typedef vector<V> VV;
typedef vector<P> VP;
ll mod = 1e9 + 7;
unsigned long long MOD = 1e9 + 7;
ll INF = 1e18;
ll v, e;
VV gragh;
V in_num;
void dfs(ll x)
{
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> v >> e;
    gragh.resize(v);
    in_num.resize(v);
    rep(i, e)
    {
        ll x, y;
        cin >> x >> y;
        gragh[x].push_back(y);
        in_num[y]++;
    }
    queue<ll> q;
    rep(i, v)
    {
        if (in_num[i] == 0)
            q.push(i);
    }
    V result;
    while (!q.empty())
    {
        ll x = q.front();
        q.pop();
        result.push_back(x);
        rep(i, gragh[x].size())
        {
            in_num[gragh[x][i]]--;
            if (in_num[gragh[x][i]] == 0)
            {
                q.push(gragh[x][i]);
            }
        }
    }
    rep(i,v){
        cout << result[i] << endl;
    }
}

