#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <queue>
#include <deque>
#include <string>
#include <sstream>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <stack>
#include <cstdio>
#include <climits>
#include <tuple>
#include <ctime>
#include <cstring>
#include <numeric>
#define FOR(i,a,n) for (int i = a; i < n; i++)
#define IFOR(i,n,a) for (int i = n; i >= a; i--)
#define mp make_pair
#define full(a) a.begin(), a.end()
#define sz(x) ((int)(x).size())
#define pii pair<int, int>
#define trav(a,x) for (auto& a : x)
using ull = unsigned long long;
using ll = long long;
using ld = long double;
using namespace std;
const ll mod = 1e9 + 7;
const int N = 5005;

ld exp(int& a)
{
    ld p = ld(1 / ld(a));
    ld ans = 0;
    FOR(i, 1, a + 1)
    {
        ans += ld(p * ld(i));
    }
    return ans;
}

void solve()
{
    int n, k; cin >> n >> k;
    ld res = 0;
    map<int, ld> m;
    vector<int> v(n);
    FOR(i, 0, k)
    {
        int a; cin >> a;
        v[i] = a;
        if (m.find(a) != m.end())
        {
            res += m[a];
            continue;
        }
        m[a] = exp(a);
        res += m[a];
    }
    ld mx = res;
    FOR(i, k, n)
    {
        int l = v[i - k];
        int r; cin >> r;
        v[i] = r;
        res -= m[l];
        if (m.find(r) != m.end())
        {
            res += m[r];
            mx = max(mx, res);
            continue;
        }
        m[r] = exp(r);
        res += m[r];
        mx = max(mx, res);
    }
    cout << setprecision(7) << fixed << mx;

}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    /*int tc;  cin >> tc;
    while (tc--)*/
    solve();
    return 0;
}





