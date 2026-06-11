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
    vector<vector<int>> v(3, vector<int>(3));
    vector<vector<bool>> mark(3, vector<bool>(3));
    FOR(i, 0, 3)
    {
        FOR(j, 0, 3)
        {
            cin >> v[i][j];
        }
    }
    int n; cin >> n;
    FOR(k, 0, n)
    {
        int b; cin >> b;
        FOR(i, 0, 3)
        {
            FOR(j, 0, 3)
            {
                if (v[i][j] == b)
                {
                    mark[i][j] = 1;
                }
            }
        }
    }
    FOR(i, 0, 3)
    {
        if (mark[i][0] && mark[i][1] && mark[i][2])
        {
            cout << "Yes";
            return;
        }
        if (mark[0][i] && mark[1][i] && mark[2][i])
        {
            cout << "Yes";
            return;
        }
    }
    if (mark[0][0] && mark[1][1] && mark[2][2])
    {
        cout << "Yes";
        return;
    }
    if (mark[0][2] && mark[1][1] && mark[2][0])
    {
        cout << "Yes";
        return;
    }
    cout << "No";
}


int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); //cout.tie(NULL);
    /*int tc; cin >> tc;
    while (tc--)*/
    solve();

    return 0;
}
