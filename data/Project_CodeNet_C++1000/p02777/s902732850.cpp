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

void solve()
{
    string s, t; cin >> s >> t;
    map<string, int> m;
    int a, b; cin >> a >> b;
    m[s] = a;
    m[t] = b;
    string j; cin >> j;
    m[j]--;
    cout << m[s] << " " << m[t];
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    /*int tc;  cin >> tc;
    while (tc--)*/
        solve();
    return 0;
}





