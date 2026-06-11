#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <numeric>
#include <ctime>
#include <complex>
#include <bitset>
#include <random>
#include <climits>
#include <stack>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll
#define double ld
#define loop(i, n) for(int i = 0; i < (int)n; ++i)
#define loop1(i, n) for(int i = 1; i <= (int)n; ++i)
#define F first
#define S second
#define pb push_back
#define pi pair <int, int>
#define all(x) begin(x), end(x)
#define ti tuple <int, int, int>
#define Point Vect
#define no {cout << -1; return;}
#define yes {cout << "Yes"; return;}
#define mkp make_pair
#define mkt make_tuple
#define cerr if(0) cerr

const int N = 1e5 + 7;

int p[N];

void solve() {
    int n, m;
    string s;
    cin >> n >> m >> s;
    deque <pi> q;
    q.pb({ 0, 0 });
    loop1(i, n) {
        if (q.empty())
            no;
        if (s[i] == '0') {
            p[i] = q.front().S;
            pi newp = { q.front().F + 1, i };
            while (q.back().F > newp.F)
                q.pop_back();
            q.pb(newp);
        }
        if (q.front().S == i - m)
            q.pop_front();
    }
    vector <int> ans;
    for (int i = n; i; i = p[i])
        ans.pb(i - p[i]);
    reverse(all(ans));
    for (int x : ans)
        cout << x << " ";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
