//K-OS WITH THE OCDE

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#include <iostream>
#include <numeric>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <stack>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <deque>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <climits>

using namespace std;

typedef long long int ll;
typedef long double db;


#define TEST ll t; cin>>t; while(t--)
#define vell vector<ll>
#define pl pair<ll,ll>
#define all(v) v.begin(),v.end()
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define dbg(x)  cerr << #x << ": "<< x <<endl
#define dbg2(x,y) cerr<< #x <<": "<< x <<" || "<< #y << ": " << y << endl

#define endl "\n"
#define MAX 1e18
#define MIN INT_MIN
#define mod 1000000007


const ll mxn = 1e5 + 5;
vector <ll> v[mxn];
bool vis[mxn] = {false};

void dfs(ll x)
{
    vis[x] = true;

    for (auto it : v[x])
        if (!vis[it])
            dfs(it);

}


void solve()
{
    ll n , m;
    cin >> n >> m;

    while (m--) {
        ll x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }

    ll f = 0;

    for (ll i = 1 ; i <= n ; ++i) {

        if (vis[i])
            continue;

        dfs(i);
        f++;
    }

    cout << f - 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0); cin.tie(0);
    //TEST
    solve();
}

