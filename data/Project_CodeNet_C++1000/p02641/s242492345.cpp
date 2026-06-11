#include <bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vi>
#define vll vector<ll>
#define vpii vector<pair<int, int>>
#define pii pair<int, int>
#define ar array
#define vvll vector<vll>
#define repa(i, b, n) for (int i = b; i < n; i++)
#define rep(i, n) for (int i = 0; i < n; i++)
#define INF 1e9
#define MP make_pair
#define ll long long int
#define M 1000000007
#define all(a) a.begin(), a.end()
// debugging
#define db(x) cout << x << "\n";
#define db1(x) cout << #x << "=" << x << "\n"
#define db2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << "\n"
#define db3(x, y, z) cout << #x << "=" << x << ", " << #y << "=" << y << ", " << #z << "=" << z << "\n"
#define dba(x)       \
    for (auto i : x) \
    cout << i << "\t"
#define dbm(x)                \
    for (auto i : x)          \
    {                         \
        for (auto j : i)      \
            cout << j << " "; \
        cout << "\n";         \
    }
#define MOD 1000000007
using namespace std;
const int maxN = 100000;
void solve()
{
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x, n;
    cin >> x >> n;
    vi a(n);
    set<int> st;
    rep(i, n) cin >> a[i], st.insert(a[i]);
    int ans = INT_MAX, xx = INT_MAX;
    for (int i = x; i <= 101; i++)
    {
        if (st.find(i) == st.end())
        {
            if (abs(x - i) <= ans)
            {
                ans = abs(x - i);
                xx = min(xx, i);
            }
        }
    }

    for (int i = x; i >= -101; i--)
    {
        if (st.find(i) == st.end())
        {

            if (abs(x - i) <= ans)
            {

                ans = abs(x - i);
                xx = min(xx, i);
            }
        }
    }

    db(xx);
}