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
const int N = 2e5 + 5;



void solve()
{
    int n, m; cin >> n >> m;
    string res(n, '$');
    FOR(i, 0, m)
    {
        int s, c; cin >> s >> c;
        if (res[s - 1] != '$' && res[s - 1] != (c + '0'))
        {
            cout << "-1\n";
            return;
        }
        res[s - 1] = (c + '0');
    }
    if (res[0] == '0' && n != 1)
    {
        cout << "-1\n";
        return;
    }
    FOR(i, 0, n)
    {
        if (res[i] == '$')
        {
            if (i == 0 && n != 1) res[0] = '1';
            else res[i] = '0';
        }
    }
    cout << res;
}


int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); //cout.tie(NULL);
    /*int tc; cin >> tc;
    while (tc--)*/
        solve();

    return 0;
}