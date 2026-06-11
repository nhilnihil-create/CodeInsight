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
#define FOR(i,a,n) for (int i = a; i < n; i++)
#define IFOR(i,n,a) for (int i = n; i >= a; i--)
#define mp make_pair
#define full(a) a.begin(), a.end()
#define sz(x) ((int)(x).size())
#define pii pair<int, int>
#define trav(a,x) for (auto& a : x)
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
using namespace std;
const int mod = 998244353;
const int N = 1e5 + 5;



int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s, t; cin >> s >> t;
    vector<vector<int>> v(26);
    int n = sz(s);
    FOR(i, 0, n)
    {
        v[s[i] - 'a'].push_back(i);
    }
    ll res = 0;
    int ind = -1, tmp = -1;
    int _size = sz(t);
    FOR(i, 0, _size)
    {
        if (sz(v[t[i] - 'a']) == 0)
        {
            cout << -1;
            return 0;
        }
        auto it = upper_bound(full(v[t[i] - 'a']), ind);
        if (it != v[t[i] - 'a'].end())
        {
            tmp = *it;
            if (ind == -1) res += (tmp + 1);
            else res += (tmp - ind);
            ind = tmp;
        }
        else
        {
            res += (n - ind - 1);
            ind = -1;
            i--;
        }
    }
    cout << res;
    return 0;
}

